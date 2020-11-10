	global ft_strcpy

ft_strcpy:
	mov rax, -1				; i = -1;
	
.loop:
	inc rax					; ++i
	mov dl, byte[rsi+rax]	; char c = src[i]
	mov byte[rdi+rax], dl	; dest[i] = c
	cmp	dl,0				; if (c != 0)
	jne .loop				; go to loop
	mov rax,rdi				; rax = dest
	ret						; return rax
