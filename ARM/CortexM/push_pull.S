.section .vectors
vector_table:
    /* documentation: readable/writable stack region 
    starts at 2000 0000 but we have to use the space abve. 
    The stack below this addr is prohibited */
    .word 0x20001000 // adding 1000 (4kb) at the top (arbitrary)
    .word reset_handler
    .zero 400

    .section .text
    .align 1
    .type reset_handler, %function
reset_handler:
    mov r1, #7
    mov r2, #3

    push {r1, r2}

    mov r1, #5
    mov r2, #6

    pop {r1, r2}

    bl .
