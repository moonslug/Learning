.data
Alphabet: .ascii "abcdefghijklmnopqrstuvwxyz"
    .align 2
dest: .skip 40

.text
.global _start
_start:
//Pre-indexed
    //calculate new address, then perform the op
    //option to update the base address

    ldr r0, =Alphabet
//register immediate
    ldr r1, [r0]

//immediate offset
    ldr r2, [r0, #4] 

//register offset
    mov r4, #8
    ldr r3, [r0, r4]! 

//scaled register offset   
    ldr r5, [r0, r4, lsl #1]

//------------------------
    ldr r0, =dest
    str r1, [r0]
    str r2, [r0, #4]

//post-indexed
    ldr r0, =Alphabet
    ldr r1, [r0], #4
    ldr r2, [r0], r4
    ldr r3, [r0], r4, lsl #1

//-----------
    ldr r0, =Alphabet
    ldr r1, [r0, #4]
    ldr r2, [r0], #4

//shifting and roration
    //0010 --> 2
    //0100 --> 4    LSL always inserts a zero to the right
    //0001 --> 1    ASR always repeats the Most Significant Bit

    //1010
    //1101 --> repeat the MSB when ASER

    mov r1, #0xf
    lsl r1, #1

    mov r2, #16
    asr r2, #1
    
    mov r3, 20
    ror r3, #1
    ror r3, #1
    ror r3, #1
    ror r3, #1

.end
