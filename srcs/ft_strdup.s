extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

ft_strdup:
	call ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call malloc
	pop rsi
	mov rdi, rax
	call ft_strcpy
	ret