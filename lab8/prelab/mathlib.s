	;; Matt Calayo mjc5gh 3/27/18 mathlib.s
	global product
	global power

	section .text

product:
	
	xor 	rax, rax
	xor	r10, r10
start:
	cmp	r10, rsi
	je	done
	add	rax, rdi
	inc	r10
	jmp	start
done:
	ret

	;; im sorry it doesnt work :(
power:
	cmp	rsi, 0
	jg	start2
	mov	rax, 1
	jmp	done
start2:

	dec	rsi
	push	rsi
	call	power
	mov	rsi, rax
	call 	product
	pop	rsi
done2:
	ret
