	;; Matt Calayo mjc5gh 4/8/18 threexplusone.s
	global threexplusone

	section .text

threexplusone:
	xor rax, rax

threexplusoneloop:	

	cmp rdi, 1
	je base

	test rdi, 1
	jz even
	jmp odd

even:
	sar rdi, 1
	jmp loopy

odd:
	imul rdi, 3
	inc rdi
	jmp loopy

loopy:
	call threexplusoneloop
	inc rax
	jmp base

base:
	ret
