	global ft_list_size

ft_list_size:
	xor rax, rax
	cmp rdi, 0
	je .end

.loop:
	inc rax
	mov rdi, qword[rdi + 8]
	cmp rdi, 0
	jne .loop

.end:
	ret
