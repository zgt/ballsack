	;; Matt Calayo mjc5gh 4/8/18 threexplusone.s
	global threexplusone

	section .text

threexplusone:
	xor rax, rax		;when I first wrote my function it was fairly omptimized I think. I don't push anything to the stack at all and it was fairly short.

threexplusoneloop:	

	cmp rdi, 1
	je base

	test rdi, 1 		;compares the bits of rdi and 1 and if they are the same then the number is even
	jz even
	jmp odd

even:
	sar rdi, 1
	jmp loopy

odd:
	lea rdi, [rdi * 2 + rdi +1] ;combined the multiply and adding to one line using lea
	jmp loopy

loopy:
	call threexplusoneloop
	inc rax
	jmp base

base:
	ret
