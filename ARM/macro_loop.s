.data

.text
.global _start
_start:

.macro enum from=0, to=6
	.word \from

	.if \from-\to
		enum "\from+1",\to
	.endif
.endm

mov r0, #10
enum

end: b end
.end
