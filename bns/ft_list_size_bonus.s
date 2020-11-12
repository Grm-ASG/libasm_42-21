	global ft_list_size

ft_list_size:
	cmp rdi, 0
	je FT_NULL_PTR
	mov rax, 0

.loop:
	inc rax
	mov rdi, qword[rdi + 8]
	cmp rdi, 0
	jne .loop
	ret

FT_NULL_PTR:
	xor rax, rax
	ret
