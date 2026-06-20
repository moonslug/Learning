// A program to count the # of char in a given string

.data

msg:    .asciz "Hello ARM!"

.text
.global _start
_start:
    ldr r0, =msg
    mov r1, #0
    mov r2, #0

    ldrb r1, [r0], #1
    cmp r1, #0
    addne r2, #1
    bne loop

.end