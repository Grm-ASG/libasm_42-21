extern __errno_location
	global ft_read

ft_read:
	xor rax, rax ; rax = 0
	syscall
	cmp rax, 0
	jl .error
	ret

.error:
	neg rax
	push rax
	call __errno_location
	pop	rdx
	mov	[rax], rdx
    mov rax, -1				; rax = -1
    ret						; return rax