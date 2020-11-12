extern __errno_location
extern malloc
	global ft_list_push_front

;void 		ft_list_push_front(t_list **head, void *data)

ft_list_push_front:
	push rdi
	push rsi
	mov rdi, 16
	call malloc
	cmp rax, 0
	jl .error
	pop rsi
	pop rdi
	mov qword[rax], rsi
	mov rcx, qword[rdi]
	mov qword[rax + 8], rcx
	mov qword[rdi], rax

.end:
	xor	rax, rax
	ret

.error:
	neg rax
	push rax
	call __errno_location
	pop	rdx
	mov	[rax], rdx
    mov rax, -1				; rax = -1
    ret						; return rax