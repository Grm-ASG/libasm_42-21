/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:39:42 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/17 16:24:46 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
		ft_check_list_size();
		ft_check_list_push_front();
	#endif
	return (0);
}

#ifndef BONUS_PART
void	ft_check_strlen(char *s[])
{
	for (int i = 0; i < 3; ++i)
	{
		printf("\n======TESTING STRLEN № %d======\n", i + 1);
		printf("|    orig strlen   =  %3ld    |\n", strlen(s[i]));
		printf("|    asm  strlen   =  %3ld    |\n", ft_strlen(s[i]));
		printf("==============================\n");
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
		printf("\n======TESTING STRCPY № %d======\n", i + 1);
		ft_bzero(buf, sizeof(buf));
		buf = strcpy(buf, s[i]);
		buf2 = ft_strcpy(buf2, s[i]);
		printf("    orig strcpy	= |%s|\n", buf);
		printf("    asm  strcpy	= |%s|\n", buf2);
		printf("==============================\n");
	}
	free(buf);
	free(buf2);
}

void	ft_check_strcmp(void)
{
	int k;
	char const *s[11] = {
		"",
		"qwer",
		"qwert",
		"asdf",
		"hello world",
		"hello world,",
		"\x01",
		"\x01",
		"asdfas",
		""
	};

	for(int i = 0; i < 9; ++i)
	{
		printf("\n======TESTING STRCMP № %d======\n", i + 1);
 		printf("|   orig strcmp	  = %5d    |\n", strcmp(s[i], s[i+1]));
 		printf("|   asm  strcmp	  = %5d    |\n", ft_strcmp(s[i], s[i+1]));
		printf("==============================\n");
		k = i;
	}
	printf("\n======TESTING STRCMP № %d=====\n", k + 2);
	printf("|   orig strcmp	  = %5d    |\n", strcmp("\x01", "\x01"));
	printf("|   asm  strcmp	  = %5d    |\n", ft_strcmp("\x01", "\x01"));
	printf("==============================\n");
}

#define WRITE_CONF fd,"unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia" 

#define WRITE_CONF2 fd2,"unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia" 

#define SCALE 20

void	ft_check_write(void)
{
	const int scale = SCALE;
	int fd = open("write_example_asm.txt", O_CREAT | O_RDWR | O_TRUNC);
	int fd2 = open("write_example_orig.txt", O_CREAT | O_RDWR | O_TRUNC);
	for (int i = 0; i < 3; ++i)
	{
		errno = 0;
		printf("\n======TESTING WRITE № %d=======\n", i + 1);
		printf("|   asm   ret	 = %6ld    |\n", ft_write(WRITE_CONF, i * scale));
		printf("|   errno status = %6d    |\n", errno);
		ft_write(fd, "\n", 1);
		errno = 0;
		printf("|   write ret	 = %6ld    |\n", write(WRITE_CONF2, i * scale));
		printf("|   errno status = %6d    |\n", errno);
		printf("==============================\n");
		write(fd2, "\n", 1);
	}
	close (fd);
}

void	ft_check_read()
{
	const int	scale = SCALE;
	char		buf[1000];
	char		buf2[1000];

	int fd_example = open("write_example_asm.txt", O_RDONLY);
	int fd_example2 = open("write_example_orig.txt", O_RDONLY);

	int fd_asm = open("read_asm.txt", O_CREAT | O_RDWR | O_TRUNC);
	int fd_orig = open("read_orig.txt", O_CREAT | O_RDWR | O_TRUNC);

	for (int i = 0; i < 3; ++i)
	{
		printf("\n======TESTING READ № %d=======\n", i + 1);
		errno = 0;

		ft_bzero(buf, sizeof(buf));
		printf("|   asm   ret	 = %6ld    |\n", ft_read(fd_example, buf, i * scale));
		write(fd_asm, buf, i * scale);

		printf("|   errno status = %6d    |\n", errno);

		errno = 0;

		ft_bzero(buf2, sizeof(buf2));
		printf("|   read  ret	 = %6ld    |\n", read(fd_example2, buf2, i * scale));
		write(fd_orig, buf2, i * scale);

		printf("|   errno status = %6d    |\n", errno);
		printf("==============================\n");
	}
	close (fd_example);
	close (fd_asm);
	close (fd_orig);
}

void	ft_check_strdup(char *s[])
{
	char	*str = NULL;
	char	*str2 = NULL;
	int		err_no[2];
	
	for (int i = 0; i < 3; ++i)
	{
		printf("\n======TESTING STRDUP № %d======\n", i + 1);
		printf("orig	strdup		= |%s|\n", (str = strdup(s[i])));
		err_no[0] = errno;
		errno = 0;
		printf("asm	strdup		= |%s|\n", (str2 = ft_strdup(s[i])));
		err_no[1] = errno;
		if (str)
			printf("orig	strlen		= %5d\n", (int)strlen(str));
		if (str2)
			printf("asm	strlen		= %5d\n", (int)strlen(str2));
		printf("orig	errno status	= %5d\n", err_no[0]);
		free(str);
		printf("asm	errno status	= %5d\n", err_no[1]);
		free(str2);
		errno = 0;
	}
}
#endif

#ifdef BONUS_PART

#define NUMBER 20
void	ft_check_list_size(void)
{
	t_list *head;
	t_list *tmp;

	head = NULL;
	for (long i = 1; i <= NUMBER; ++i)
	{
		ft_list_push_front(&head, (void *)i);
	}
	printf("\nsize of list = %d\n\n", ft_list_size(head));

	tmp = head;
	for (int i = NUMBER; i > 0; i--)
	{
		printf("i		= %d\n", i);
		printf("Adr_tmp		= %p\n", tmp);
		int x = *((int*)(&tmp->data));
		printf("tmp->data	= %d\n", x);
		printf("tmp->next	= %p\n\n", (void *)tmp->next);
		tmp = tmp->next;
	}
}

void 	ft_check_list_push_front(void)
{
	t_list *head;
	long value = 100;

	head = NULL;
	printf("Adr_head	= %p\n", head);
	printf("data		= %ld\n\n", value);

	ft_list_push_front(&head, (void *)value);
	printf("Adr_head	= %p\n", head);
	long x = *((long*)(&head->data));
	printf("head->data	= %d\n\n", x);
}
#endif