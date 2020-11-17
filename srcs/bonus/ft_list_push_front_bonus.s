extern __errno_location
extern malloc
	global ft_list_push_front

;	void 		ft_list_push_front(t_list **head, void *data)

ft_list_push_front:
	push rdi					;	save rdi on the stack
	push rsi					;	save rsi on the stack
	mov rdi, 16					;	set rdi to value 16
	call malloc					;	call malloc with allocating 16 bytes
	pop rsi						;	get value from stack
	pop rdi						;	get value from stack
	cmp rax, 0					;	check return value of malloc
	je .error					;	if error occures jump to .error
	mov qword[rax], rsi			;	list.value = data
	mov rcx, qword[rdi]			;	rcx = *head
	mov qword[rax + 8], rcx		;	list.next = rcx
	mov qword[rdi], rax			;	head = list
	jmp .end

.error:
	neg rax						;	rax = rax * -1
	mov rdx, rax				;	rdx = rax
	call __errno_location		;	rax = &errno
	mov	[rax], rdx				;	errno = rdx
	
.end:
	ret							;	return ;