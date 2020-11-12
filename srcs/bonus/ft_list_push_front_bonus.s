extern __errno_location
extern malloc
	global ft_list_push_front

;	void 		ft_list_push_front(t_list **head, void *data)

ft_list_push_front:
	push rdi					;	save rdi on the stack
	push rsi					;	save rsi on the stack
	mov rdi, 16					;	set rdi to value 16
	call malloc					;	call malloc with allocating 16 bytes
	cmp rax, 0					;	check return value of malloc
	jl .error					;	if error occures jump to .error
	pop rsi						;	get value from stack
	pop rdi						;	get value from stack
	mov qword[rax], rsi			;	list.value = data
	mov rcx, qword[rdi]			;	rcx = *head
	mov qword[rax + 8], rcx		;	list.next = rcx
	mov qword[rdi], rax			;	head = list

.end:
	xor	rax, rax				;	rax to zero, why not?
	ret							;	return ;

.error:
	neg rax						;	rax = rax * -1
	mov rdx, rax				;	rdx = rax
	call __errno_location		;	rax = &errno
	mov	[rax], rdx				;	errno = rdx
    ret							;	return ;