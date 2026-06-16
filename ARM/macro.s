.data

.text
.global _start
_start:

.macro check p1
	.if \p1==0
		mov r1, #0
	.else
		mov r1, #1		
	.endif
.endm
	
	mov r2, #6
	check r2
	
end:	b end
.end