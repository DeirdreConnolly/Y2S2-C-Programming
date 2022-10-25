#!/usr/bin/tclsh

# Program: lib_mr.tcl
# Written by: Josep Sanz
# Date: November of 2001

# convert from binary to decimal
proc bin2dec {num} {
  set result 0
  if {[string index $num 0] == "-"} {
    set signe "-"
    set num [string range $num 1 end]
  } else {
    set signe ""
  }
  set len [string length $num]
  for {set i [expr $len - 1]} {$i>=0} {incr i -1} {
    set valpot [expr int(pow(2,$i))]
    set valbit [string index $num [expr $len - $i - 1]]
    set result [expr $result + $valbit * $valpot]
  }
  return "$signe$result"
}

# convert hexadecimal to decimal (new version)
proc hex2dec {num} {
  return [expr 0x$num]
}

# convert from decimal to binary
proc dec2bin {num dig} {
  set result ""
  if {[string index $num 0] == "-"} {
    set signe "-"
    set num [string range $num 1 end]
  } else {
    set signe ""
  }
  for {set i 0} {$i < $dig} {incr i 1} {
    set valbit [expr $num % 2]
    set result "$valbit$result"
    set num [expr $num /2]
  }
  return "$signe$result"
}

# convert from decimal to hexadecimal
proc dec2hex {num dig} {
  set result ""
  if {[string index $num 0] == "-"} {
    set signe "-"
    set num [string range $num 1 end]
  } else {
    set signe ""
  }
  set valhex {0 1 2 3 4 5 6 7 8 9 A B C D E F}
  for {set i 0} {$i < $dig} {incr i 1} {
    set valbit [expr $num % 16]
    set result "[lindex $valhex $valbit]$result"
    set num [expr $num / 16]
  }
  return "$signe$result"
}

# convert from binary to hexadecimal
proc bin2hex {num dig} {
  return [dec2hex [bin2dec $num] $dig]
}

# convert from hexadecimal to binary
proc hex2bin {num dig} {
  return [dec2bin [hex2dec $num] $dig]
}

# recognize the format of num and convert to binary
proc num2bin {num dig} {
  set base [string tolower [string index $num end]]
  set reg [string toupper [string index $num 0]]
  set num2 [string range $num 0 [expr [string length $num] - 2]]
  set num3 [string range $num 1 end]
  if {$reg == "#"} {
    return [num2bin $num3 $dig]
  } elseif {$reg == "R"} {
    return [dec2bin $num3 $dig]
  } elseif {$base == "h"} {
    return [hex2bin $num2 $dig]
  } elseif {$base == "b"} {
    return [set result $num2]
  } elseif {$base == "d"} {
    return [dec2bin $num2 $dig]
  } else {
    return [dec2bin $num $dig]
  }
}

# recognize the format and convert to decimal
proc num2dec {num} {
  return [bin2dec [num2bin $num 16]]
}

# recognize the format and convert to hexadecimal
proc num2hex {num dig} {
  return [bin2hex [num2bin $num [expr $dig * 4]] $dig]
}

# convert a decimal to CA2 binary
proc dec2ca2 {num dig} {
  if {$num < 0} {set num [expr int(pow(2,$dig)) + $num]}
  return [dec2bin $num $dig]
}

# convert a CA2 binary to decimal
proc ca22dec {num} {
  set result [bin2dec $num]
  if {[string index $num 0] == "1"} {
    set dig [string length $num]
    set result [expr $result - int(pow(2,$dig))]
  }
  return $result
}

# implement the AND instruction for 16 bits
proc and16 {num num2} {
  set result ""
  for {set i 0} {$i < 16} {incr i 1} {
    set result "$result[expr [string index $num $i] * [string index $num2 $i]]"
  }
  return $result
}

# implement the aritmetic shift right with signe replication
proc asr16 {num} {
  return "[string index $num 0][string range $num 0 14]"
}

# convert from assembler to binary codification
proc asm2cod {asm} {
  set asm [exec echo $asm | tr ",()" " "]
  for {set i 2} {$i <= 5} {incr i 1} {set l$i ""}
  scan $asm "%s %s %s %s" l2 l3 l4 l5
  set result ""
  if {[string toupper $l2] == "LOAD"} {
    set Rd [num2bin $l5 3]
    set Ri [num2bin $l4 3]
    set mem [num2bin $l3 8]
    return "00$Rd$Ri$mem"
  } elseif {[string toupper $l2] == "STORE"} {
    set Rf [num2bin $l3 3]
    set mem [num2bin $l4 8]
    set Ri [num2bin $l5 3]
    return "01$Rf$Ri$mem"
  } elseif {[string toupper [string index $l2 0]] == "B"} {
    switch [string toupper [string range $l2 1 2]] {
      R  {set COND 000}
      EQ {set COND 001}
      L  {set COND 010}
      LE {set COND 011}
      NE {set COND 101}
      GE {set COND 110}
      G  {set COND 111}
    }
    set mem [num2bin $l3 8]
    return [format "10%s000%s" $COND $mem]
  } elseif {[string toupper [string index $l2 0]] == "A" || [string toupper [string index $l2 0]] == "S"} {
    switch [string toupper $l2] {
      ADDI {set OP 000}
      SUBI {set OP 001}
      ADD  {set OP 100}
      SUB  {set OP 101}
      ASR  {set OP 110}
      AND  {set OP 111}
    }
    set Rf1 [num2bin $l3 3]
    set DIF ""
    if {$OP == 110} {
      set Rf2 000
      set DIF 00
      set Rd [num2bin $l4 3]
    } else {
      switch [string index $OP 0] {
        0 {set Rf2 [dec2ca2 [num2dec $l4] 5]; set DIF ""}
        1 {set Rf2 [num2bin $l4 3]; set DIF 00}
      }
      set Rd [num2bin $l5 3]
    }
    return "11$Rd$Rf1$Rf2$DIF$OP"
  } else {
    return [dec2ca2 [num2dec $l2] 16]
  }
}

proc cod2asm {cod} {
  set COD [string range $cod 0 1]
  if {$COD == 00} {
    set Rd [bin2dec [string range $cod 2 4]]
    set Ri [bin2dec [string range $cod 5 7]]
    set mem [bin2hex [string range $cod 8 15] 2]
    return [format "LOAD %sh(R%s),R%s" $mem $Ri $Rd]
  } elseif {$COD == 01} {
    set Rf [bin2dec [string range $cod 2 4]]
    set Ri [bin2dec [string range $cod 5 7]]
    set mem [bin2hex [string range $cod 8 15] 2]
    return [format "STORE R%s,%sh(R%s)" $Rf $mem $Ri]
  } elseif {$COD == 10} {
    set COND [string range $cod 2 4]
    set mem [bin2hex [string range $cod 8 15] 2]
    switch $COND {
      000 {set COND BR}
      001 {set COND BEQ}
      010 {set COND BL}
      011 {set COND BLE}
      101 {set COND BNE}
      110 {set COND BGE}
      111 {set COND BG}
    }
    return [format "%s %sh" $COND $mem]
  } elseif {$COD == 11} {
    set Rd [bin2dec [string range $cod 2 4]]
    set Rf1 [bin2dec [string range $cod 5 7]]
    set Rf2 [bin2dec [string range $cod 8 10]]
    set i [ca22dec [string range $cod 8 12]]
    set OP [string range $cod 13 15]
    switch $OP {
      000 {return [format "ADDI R%s,#%s,R%s" $Rf1 $i $Rd]}
      001 {return [format "SUBI R%s,#%s,R%s" $Rf1 $i $Rd]}
      100 {return [format "ADD R%s,R%s,R%s" $Rf1 $Rf2 $Rd]}
      101 {return [format "SUB R%s,R%s,R%s" $Rf1 $Rf2 $Rd]}
      110 {return [format "ASR R%s,R%s" $Rf1 $Rd]}
      111 {return [format "AND R%s,R%s,R%s" $Rf1 $Rf2 $Rd]}
    }
  }
}

proc makeComment {doc prog} {
  global env
  return "# $doc generated by $prog at [clock format [clock seconds] -format "%H:%M %d/%m/%y"] by user $env(USER)"
}

