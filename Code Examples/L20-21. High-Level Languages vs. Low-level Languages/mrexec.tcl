#!/usr/bin/tclsh

# Program: mrexec.tcl
# Written by: Josep Sanz
# Date: November of 2001

# define and include the library
source libmr.tcl

# define the registers, memory and condition bits (by default, indeterminate)
for {set i 0} {$i < 8} {incr i 1} {set REG($i) XXXXXXXXXXXXXXXX}
for {set i 0} {$i < 256} {incr i 1} {set MEM($i) XXXXXXXXXXXXXXXX}
set N X
set Z X
set PC X

# maintain R0 equal to zero
proc clearR0 {} {
  global REG
  set REG(0) "0000000000000000"
}

# this procedure execute a instruction
proc execute {cod} {
  global REG MEM N Z PC
  clearR0
  set COD [string range $cod 0 1]
  if {$COD == 00} {
    set Rd [bin2dec [string range $cod 2 4]]
    set Ri $REG([bin2dec [string range $cod 5 7]])
    set mem [bin2dec [string range $cod 8 15]]
    set REG($Rd) $MEM([expr $mem + $Ri])
    set N [string index $REG($Rd) 0]
    if {[bin2dec $REG($Rd)] == 0} {set Z 1} else {set Z 0}
    clearR0
  } elseif {$COD == 01} {
    set Rf [bin2dec [string range $cod 2 4]]
    set Ri $REG([bin2dec [string range $cod 5 7]])
    set mem [bin2dec [string range $cod 8 15]]
    clearR0
    set MEM([expr $mem + $Ri]) $REG($Rf)
  } elseif {$COD == 10} {
    set COND [string range $cod 2 4]
    set mem [expr [bin2dec [string range $cod 8 15]] - 1]
    switch $COND {
      000 {set PC $mem}
      001 {if {$Z == 1} {set PC $mem}}
      010 {if {$N == 1} {set PC $mem}}
      011 {if {$N == 1 || $Z == 1} {set PC $mem}}
      101 {if {$Z == 0} {set PC $mem}}
      110 {if {$N == 0} {set PC $mem}}
      111 {if {$N == 0 && $Z == 0} {set PC $mem}}
    }
  } elseif {$COD == 11} {
    set Rd [bin2dec [string range $cod 2 4]]
    set Rf1 $REG([bin2dec [string range $cod 5 7]])
    set Rf1d [ca22dec $Rf1]
    set Rf2 $REG([bin2dec [string range $cod 8 10]])
    set Rf2d [ca22dec $Rf2]
    set i [ca22dec [string range $cod 8 12]]
    set OP [string range $cod 13 15]
    switch $OP {
      000 {set REG($Rd) [dec2ca2 [expr $Rf1d + $i] 16]}
      001 {set REG($Rd) [dec2ca2 [expr $Rf1d - $i] 16]}
      100 {set REG($Rd) [dec2ca2 [expr $Rf1d + $Rf2d] 16]}
      101 {set REG($Rd) [dec2ca2 [expr $Rf1d - $Rf2d] 16]}
      110 {set REG($Rd) [asr16 $Rf1]}
      111 {set REG($Rd) [and16 $Rf1 $Rf2]}
    }
    set N [string index $REG($Rd) 0]
    if {[bin2dec $REG($Rd)] == 0} {set Z 1} else {set Z 0}
    clearR0
  }
}

proc quit {} {
  puts "You must to specify the code file and PC direction"
  exit
}

# this is the main code
if {$argc != 2} {quit}
scan $argv "%s %s" filename pc
if {[string first ".cod" $filename] == -1} {quit}
set file [open $filename r]
while {[eof $file] == 0} { # load all instructions in memory
  gets $file cod
  if {$cod != "" && [string index $cod 0] != "#"} {
    scan $cod "%s %s" pos cod
    set pos [num2dec $pos]
    set cod [num2bin $cod 16]
    set MEM($pos) $cod
  }
}
close $file
set PC [num2dec $pc]
while {$PC < 256} { # execute all instructions
  if {$MEM($PC) == "XXXXXXXXXXXXXXXX"} {break}
  execute $MEM($PC)
  incr PC 1
}
regsub ".cod" $filename "" filename
set filename "$filename.log"
set file [open $filename w]
puts $file [makeComment log mrexec.tcl]
for {set i 1} {$i < 8} {incr i 1} { # write the log of registers
  if {$REG($i) != "XXXXXXXXXXXXXXXX"} {
    set regh [bin2hex $REG($i) 4]
    set regd [bin2dec $REG($i)]
    set asm [cod2asm $REG($i)]
    puts $file [format "R%1s  %16sb %4sh %5s %s" $i $REG($i) $regh $regd $asm]
  }
}
for {set i 0} {$i < 256} {incr i 1} { # write the log of memory
  if {$MEM($i) != "XXXXXXXXXXXXXXXX"} {
    set pos [dec2hex $i 2]
    set memh [bin2hex $MEM($i) 4]
    set memd [bin2dec $MEM($i)]
    set asm [cod2asm $MEM($i)]
    puts $file [format "%2sh %16sb %4sh %5s %s" $pos $MEM($i) $memh $memd $asm]
  }
}
close $file
puts "Writted log of execution in $filename"
