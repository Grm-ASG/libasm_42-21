/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:39:42 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/12 16:22:15 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BONUS

#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

void	ft_check_strlen(char *s[]);
void	ft_check_strcpy(char *s[]);
void	ft_check_strcmp(void);
void	ft_check_write(void);
void	ft_check_read(void);
void	ft_check_strdup(char *s[]);
void	ft_check_list_size(void);
void	ft_check_list_push_front(void);

int		main(void)
{
	#ifndef BONUS_PART
	char *s[3] =
	{
		"",
		"hello world",
		"Lorem ipsum dolor sit amet, \
 consectetur adipiscing elit. Nulla \
 ut velit quis nisl imperdiet commodo. \
 Ut quis bibendum justo, quis iaculis ligula. \
 Aliquam eget tellus gravida, consectetur dolor \
 sed, blandit leo. Nulla facilisi. Mauris pretium \
 dui ut elit finibus, id rutrum diam interdum. Lorem \
 ipsum dolor sit amet, consectetur adipiscing elit. Nulla \
 facilisi. Nullam tincidunt tempor posuere. Donec et neque eu \
 tortor molestie congue. Vivamus aliquet, odio sed ultrices efficitur\
 , ex odio rhoncus leo, vel sodales enim quam ultrices tortor. Phasellus \
 nec metus pellentesque, congue tortor nec, suscipit turpis. Nam dictum \
 malesuada elit in interdum. Pellentesque at mauris nec ligula efficitur \
 sollicitudin. Class aptent taciti sociosqu ad litora torquent per conubia \
 nostra, per inceptos himenaeos. "
	};
	/*
	**		Mandantory part
	*/

		ft_check_strlen(s);
		ft_check_strcpy(s);
		ft_check_strcmp();
		ft_check_write();
		ft_check_read();
		ft_check_strdup(s);
	#endif

	/*
	**		Bonus part
	*/

	#ifdef BONUS_PART
		//ft_check_list_size();
		ft_check_list_push_front();
	#endif
	return (0);
}

#ifndef BONUS_PART
void	ft_check_strlen(char *s[])
{
	for (int i = 0; i < 3; ++i)
	{
		printf("orig strlen	= |%ld|\n", strlen(s[i]));
		printf("asm_strlen	= |%ld|\n\n", ft_strlen(s[i]));
	}
}

void	ft_bzero(void *mem, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)mem;
	while (n--)
	*p++ = '\0';
}

void	ft_check_strcpy(char *s[])
{
	char *buf = malloc(1000);
	char *buf2 = malloc(1000);


	for (int i = 0; i < 3; ++i)
	{
		ft_bzero(buf, sizeof(buf));
		buf = strcpy(buf, s[i]);
		buf2 = ft_strcpy(buf2, s[i]);
		printf("orig strcpy	= |%s|\n", buf);
		printf("asm strcpy	= |%s|\n\n", buf2);
	}
}

void	ft_check_strcmp(void)
{
	char const *s[11] = {
		"",
		"qwer",
		"qwert",
		"asdf",
		"asdg",
		"hello world",
		"hello world,",
		"\x01",
		"\x01",
		"asdfas",
		""
	};

	for(int i = 0; i < 10; ++i)
	{
 		printf("orig strcmp = |%d|\n", strcmp(s[i], s[i+1]));
 		printf("asm  strcmp = |%d|\n\n", ft_strcmp(s[i], s[i+1]));
	}
	printf("orig strcmp = |%d|\n", strcmp("\x01", "\x01"));
	printf("asm  strcmp = |%d|\n\n", ft_strcmp("\x01", "\x01"));
}

#define WRITE_CONF 42, "bonjour", 7

void	ft_check_write(void)
{
	for (int i = 0; i < 3; ++i)
	{
		printf("\nLOOP NUMBER %d\n", i);
		printf("asm_write ret		= |%ld|\n", ft_write(WRITE_CONF));
		printf("asm_errno status	= |%d|\n", errno);
		printf("write ret		= |%ld|\n", write(WRITE_CONF));
		printf("errno status		= |%d|\n", errno);
	}
}

#define READ_CONF fd, buf, 1

void	ft_check_read()
{
	char	buf[1000];
	int		fd = 1;

	ft_bzero(buf, sizeof(buf));
	for (int i = 0; i < 3; ++i)
	{
		printf("\nLOOP NUMBER %d\n", i);
		printf("asm_read ret		= |%ld|\n", ft_read(READ_CONF));
		printf("asm_errno status	= |%d|\n", errno);
		printf("read ret		= |%ld|\n", read(READ_CONF));
		printf("errno status		= |%d|\n", errno);
	}
}

void	ft_check_strdup(char *s[])
{
	char *string;
	for (int i = 0; i < 3; ++i)
	{
		printf("\norig strdup	= |%s|\n", (string = strdup(s[i])));
		free(string);
		printf("asm strdup	= |%s|\n", (string = ft_strdup(s[i])));
		free(string);
	}
}
#endif

#ifdef BONUS_PART

#define NUMBER 0
void	ft_check_list_size(void)
{
	t_list *list;
	t_list *head;
	t_list *tmp;

	head = NULL;
	tmp = NULL;
	for (int i = 0; i < NUMBER; ++i)
	{
		
		list = malloc(sizeof(t_list));
		if (tmp)
			tmp->next = list;
		list->next = NULL;
		tmp = list;
		if (i == 0)
			head = list;
	}
	printf("\nsize of list = %d\n\n", ft_list_size(head));
}

void 	ft_check_list_push_front(void)
{
	t_list *head;
	int value = 100;

	head = NULL;
	printf("Adr_head	= %p\n", head);
	printf("data		= %d\n\n", value);

	ft_list_push_front(&head, &value);
	printf("Adr_head	= %p\n", head);
	int x = *((int*)(&head->data));
	printf("head->data	= %d\n\n", x);
}
#endif