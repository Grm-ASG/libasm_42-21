extern __errno_location
	global	ft_write

ft_write:
	mov rax, 1				; set rax to write syscall
	syscall					; rax = write(rdi, rsi, )
	cmp rax, 0				; cmp return value of write with 0
	jl .error				; if return value of syscall < 0 jump to .error
	ret						; return rax (number of writen characters)

.error:
	neg rax					;	rax = rax * -1
	mov rdx, rax			;	rdx = rax
	call __errno_location	;	rax = &errno
	mov	[rax], rdx			;	errno = rdx
    mov rax, -1				;	rax = -1
    ret						;	return rax