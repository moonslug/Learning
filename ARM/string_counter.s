.data

msg:	.asciz "Hello ARM!"

.text
.global _start 
_start:
	
	ldr r0, =msg	// load starting addr of the msg
	mov r1, #0		// starting r1 to hold the char
	mov r2, #0		// starting the counter
	
loop:
	ldrb r1, [r0], #1	// load a new char then incr by 1
	cmp r1, #0			// check for null terminator
	addne r2, #1		// if not null, add the counter by 1
	bne loop			// not null keep looping
	
.end