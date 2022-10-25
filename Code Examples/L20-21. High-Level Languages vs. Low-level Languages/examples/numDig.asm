00h 20
01h 5
02h load 00h(r0),r1
03h load 01h(r0),r2
04h addi r0,#1,r3
05h add r0,r0,r4
06h add r0,r0,r5
07h sub r2,r4,r0
08h ble 0eh
09h and r1,r3,r6
0ah add r5,r6,r5
0bH asr r1,r1
0cH addi r4,#1,r4
0dH br 07h
0eh store r5,ffh(r0)
