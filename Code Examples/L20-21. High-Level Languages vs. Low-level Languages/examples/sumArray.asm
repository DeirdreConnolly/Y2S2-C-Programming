00h 2
01h 5
02h 4
03h load 00h(r0),r1 
04h addi r0,#0,r2
05h addi r0,#0,r3
06h sub r1,r2,r0
07h ble 0ch
08h load 01h(r2),r4
09h add r3,r4,r3
0ah addi r2,#1,r2
0bh br 06h
0ch store r3,ffh(r0)
