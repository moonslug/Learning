.data

x:			.word 	5
z:			.byte 	'A'
			.align 	3
xary:		.word 	1, 2, 3, 4
chary:		.byte 	'a', 'b', 'c'
			.align 2 // skip is less convenient
chary2:		.ascii 	"abc"
			.skip 	10, 0xAF

.text
.global _start
_start:
	
	ldr r0, =x
	ldr r1, =z
	ldr r2, =xary
	ldr r3, =chary
	ldr r4, =chary2
	
.end
