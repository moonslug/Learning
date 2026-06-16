.text
.globl main

main:
    mov x8, #64          // Linux sys_write syscall number
    mov x0, #1           // File descriptor 1 (stdout)
    adr x1, msg          // Pointer to the message string
    mov x2, 13           // Length of the message
    svc #0               // Call Linux kernel

    mov x8, #93          // Linux sys_exit syscall number
    mov x0, #0           // Return status code 0
    svc #0               // Call Linux kernel

.data
msg:
    .ascii "Hello, ARM64!\n"
