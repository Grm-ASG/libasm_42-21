extern __errno_location
	global ft_read

ft_read:
	xor rax, rax 			;	rax = 0
	syscall					;	call read func
	cmp rax, 0				;	if read ret < 0
	jl .error				;	jump to .error
	ret						;	return rax

.error:
	neg rax					;	rax = rax * -1
	mov rdx, rax			;	rdx = rax
	call __errno_location	;	rax = &errno
	mov	[rax], rdx			;	errno = rdx
    mov rax, -1				;	rax = -1
    ret						;	return rax