	global penis
	global poop

	section .text

penis:
	push	rbp
	mov	rbp, rsp
	push 	rsi
	push	rbx
	push 	rdi

	xor	rax, rax
	mov	rsi, [rbp+8]
	mov	rcx, [rbp+12]
loop:
	cmp	rcx, 0
	jle	done
	add	rax, rsi
	dec	rcx
	jmp	loop

done:
	pop	rdi
	pop	rbx
	pop	rsi
	pop	rbp
	ret
	
poop:	push	rbp
	mov	rbp, rsp
	push	rdi
	push	rsi
	push	rbx

	mov	rdi, [rbp +8]
	mov	rcx, [rbp+12]
	xor	rax,rax
	cmp	rcx,0
	jg	recurse
	mov	rax,1
	jmp	end

recurse:
	dec 	rcx
	push	rcx
	push	rdi
	call	poop
	push	rax
	push	rdi
	call	penis

end:	pop	rbx
	pop	rsi
	pop	rdi
	leave
	ret
