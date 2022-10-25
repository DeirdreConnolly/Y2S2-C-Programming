00h 4
01h load 00h(r0),r1 
02h addi r0,#1,r3
03h addi r0,#1,r2
04h sub r1,r2,r0
05h ble 0dh
06h addi r2,#1,r2
07h add r3,r0,r5
08h subi r2,#1,r4
09h ble 04h
0ah add r3,r5,r3
0bh subi r4,#1,r4
0ch br 09h
0dh store r3,ffh(r0)

