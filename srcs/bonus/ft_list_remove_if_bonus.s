extern free
	global	ft_list_remove_if

;	void		ft_list_remove_if(t_list **head, void *data)

ft_list_remove_if:
	cmp rdi, 0				;	head == NULL ?
	je .end					;	jump to end
	xor rcx, rcx			;	i = 0
	mov rcx, qword[rsi]		;	rcx = data

.find_list:
	mov r8, qword[rdi]		;	r8 = *head
	mov r9, qword[r8 + 8]	;	r9 = head.next	
	cmp rcx, qword[r8]		;	rxc == head.data ?
	je .delete_list			;	jump to del instruction

.delete_list:
	mov r10, qword[r8 + 8]	;	r10 = head.next
	mov qword[r9], r10		;	last.next = head.next
	mov rdi, r8
	call free

.end
	xor rax, rax
	ret
	