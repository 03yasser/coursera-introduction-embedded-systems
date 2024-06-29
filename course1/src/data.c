/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

// #include "course1/include/common/data.h"

#include <stdlib.h>
#include <stdio.h>

typedef unsigned char	uint8_t;
typedef unsigned long	size_t;
typedef signed int		int32_t;
typedef unsigned int	uint32_t;

#ifndef NULL
#define NULL ((void*)0)
#endif


static int	ptr_lengh(int32_t data, uint32_t base)
{
	int		count;
	long	nb;

	nb = data;
	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		count++;
		nb = nb / base;
	}
	return (count);
}

uint8_t	my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	long		nb;
	int			len;
	char		*str;
	uint32_t	i;

	str = "0123456789ABCDEF";
	len = ptr_lengh(data, base);
	i = 0;
	nb = data;
	if (nb < 0)
		nb *= -1;
	while (i < len)
	{
		*(ptr + len - 1 - i) = str[nb % base];
		nb = nb / base;
		i++;
	}
	if (data < 0)
		*ptr = '-';
	*(ptr + len) = '\0';
	return (len);
}

int main()
{
	char str[20];
	my_itoa(10, str, 2);
}