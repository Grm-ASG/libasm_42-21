	global ft_strlen

ft_strlen:
	mov rax, -1			; i = -1;

.loop:	
	inc rax					; ++i
	cmp byte[rdi+rax], 0	; if (str[i] == '\0')
	jne .loop				; go to loop
	ret						; return (i);