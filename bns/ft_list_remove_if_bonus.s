extern free
	global	ft_list_remove_if

;	void		ft_list_remove_if(t_list **head, void *data)

ft_list_remove_if:
	xor rcx, rcx		;	i = 0

.find_data:
	cmp rsi, 
	