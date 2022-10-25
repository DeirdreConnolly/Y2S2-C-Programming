#!/usr/bin/tclsh

# Program: mrcomp.tcl
# Written by: Josep Sanz
# Date: November of 2001

# include the library
source libmr.tcl

proc quit {} {
  puts "You must to specify the assembler file"
  exit
}

# this is the main code
if {$argc != 1} {quit}
scan $argv "%s" filename
if {[string first ".asm" $filename] == -1} {quit}
regsub ".asm" $filename "" filename2
set filename2 "$filename2.cod"
set file [open $filename r]
set file2 [open $filename2 w]
puts $file2 [makeComment code mrcomp.tcl]
while {[eof $file] == 0} {
  gets $file asm
  if {$asm != "" && [string index $asm 0] != "#"} {
    scan $asm "%s" pos
    set pos [num2hex $pos 2]
    set instru [string range $asm [expr [string wordend $asm 0] + 1] end]
    set codb [asm2cod $instru]
    set codd [bin2dec $codb]
    set codh [dec2hex $codd 4]
    set instru [cod2asm $codb]
    puts $file2 [format "%2sh %16sb %4sh %5s %s" $pos $codb $codh $codd $instru]
  }
}
close $file
close $file2
puts "Writted binary code in $filename2"
