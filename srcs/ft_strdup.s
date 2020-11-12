extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

	global ft_strdup

ft_strdup:
	push rdi
	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc
	cmp rax, 0
	jle .error
	pop rsi
	mov rdi, rax
	call ft_strcpy
	ret

.error:
	neg rax
	push rax
	call __errno_location
	pop	rdx
	mov	[rax], rdx
    mov rax, -1				; rax = -1
    ret						; return rax