/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imedgar <imedgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:39:42 by imedgar           #+#    #+#             */
/*   Updated: 2020/11/11 16:42:35 by imedgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	ft_check_write(char *s[]);
void	ft_check_read(char *s[]);

int		main(void)
{
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
	//ft_check_strlen(s);
	//ft_check_strcpy(s);
	ft_check_strcmp();
	//ft_check_write(s);
	//ft_check_read(s);
	return (0);
}

void	ft_check_strlen(char *s[])
{
	for (int i = 0; i < 3; ++i)
	{
		printf("orig strlen	= %ld\n", strlen(s[i]));
		printf("asm_strlen	= %ld\n\n", ft_strlen(s[i]));
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
		printf("orig strcpy	= %s\n", buf);
		printf("asm strcpy	= %s\n\n", buf2);
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
 		printf("orig strcmp = %d\n", strcmp(s[i], s[i+1]));
 		printf("asm  strcmp = %d\n\n", ft_strcmp(s[i], s[i+1]));
	}
	printf("orig strcmp = %d\n", strcmp(s[1], s[1]));
	printf("asm  strcmp = %d\n\n", ft_strcmp(s[1], s[1]));

	int x, y;
	for (int j = 0; j <= 127; ++j)
	{
		x = strcmp((char *)&j, (char *)&j);
		y = ft_strcmp((char *)&j, (char *)&j);
		if (x != y)
		{
			printf("j		= %d\n", j);
			printf("orig strcmp	= %d\n", x);
			printf("asm  strcmp	= %d\n\n", y);
		}
	}
}

#define WRITE_CONF fd, "hello", 1

void	ft_check_write(char *s[])
{
	int fd = 2;
	
	for (int i = 0; i < 3; ++i)
	{
		printf("\nLOOP NUMBER %d\n", i);
		printf("asm_write ret		= %d\n", ft_write(WRITE_CONF));
		printf("asm_errno status	= %d\n", errno);
		printf("write ret		= %d\n", write(WRITE_CONF));
		printf("errno status		= %d\n", errno);
		//write(1, s[i], strlen(s[i]));
		//write(1, "\n", 1);
		//ft_write(1, s[i], strlen(s[i]));
		//write(1, "\n", 1);
		//write(1, "\n\n", 2);
	}
}

#define READ_CONF fd, buf, 1

void	ft_check_read(char *s[])
{
	char	buf[1000];
	int		fd = 2;

	ft_bzero(buf, sizeof(buf));
	for (int i = 0; i < 3; ++i)
	{
		printf("\nLOOP NUMBER %d\n", i);
		printf("asm_write ret		= %d\n", ft_read(READ_CONF));
		printf("asm_errno status	= %d\n", errno);
		printf("write ret		= %d\n", read(READ_CONF));
		printf("errno status		= %d\n", errno);
		//write(1, s[i], strlen(s[i]));
		//write(1, "\n", 1);
		//ft_write(1, s[i], strlen(s[i]));
		//write(1, "\n", 1);
		//write(1, "\n\n", 2);
	}
}