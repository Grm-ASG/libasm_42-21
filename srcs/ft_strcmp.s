	global	ft_strcmp

ft_strcmp:
	mov rax, -1
	xor rdx,rdx
	xor rcx,rcx

.loop:
	inc rax
	mov dl, byte[rdi+rax]
	mov cl, byte[rsi+rax]
	cmp dl,0
	je .end
	cmp cl,0
	je .end
	cmp dl,cl
	jne .end
	jmp .loop

.end:
	sub rdx, rcx
	mov rax, rdx
	ret
	