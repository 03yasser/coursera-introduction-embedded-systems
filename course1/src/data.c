/******************************************************************************
 * Copyright (C) 2024 by yasser boutslighoi 
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted provided this copyright notice is preserved. Users are 
 * allowed to modify this and use it for learning about embedded software. 
 *  yasser boutslighoi is not responsible for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file course1.c
 * @brief Abstraction of various data manipulation operations
 *
 * This source file provides an abstraction of various data manipulation
 * operations such as integer to ASCII conversion, ASCII to integer conversion,
 * memory move, memory copy, memory set, and string reversal via function calls.
 *
 * @author yasser boutslighoi 
 * @date June 29, 2024
 *
 */

#include "data.h"

static int	nbr_lengh(int32_t data, uint32_t base)
{
	int		count;
	long	nb;

	nb = data;
	count = 0;
	// If the input 'data' is 0, the length is 1
	if (nb == 0)
		return (1);
	// If the input 'data' is negative, increment the count and make it positive
	if (nb < 0)
	{
		count++;
		nb = nb * -1;
	}
	// Count the number of digits in the string representation of 'data' in the given 'base'
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
	// Get the length of the string representation of 'data' in the given 'base'
	len = nbr_lengh(data, base);
	i = 0;
	nb = data;
	// If the input 'data' is negative, make it positive
	if (nb < 0)
		nb *= -1;
	// Convert the integer 'data' to a string representation in the given 'base'
	while (i < len)
	{
		*(ptr + len - 1 - i) = str[nb % base];
		nb = nb / base;
		i++;
	}
	// If the input 'data' is negative, prepend a '-' to the string
	if (data < 0)
		*ptr = '-';
	// Null-terminate the string
	*(ptr + len) = '\0';
	return (len);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	short	sign;
	int32_t	result;
	uint8_t		i;

	i = 0;
	sign = 1;
	result = 0;
	// If the base is not between 2 and 16 (inclusive), return 0
	if (base > 16 || base < 2)
		return (0);
	// Check if the string starts with a sign
	if (*(ptr + i) == '-' || *(ptr + i) == '+')
	{
		if (*(ptr + i++) == '-')
			sign = -1;
	}
	// Convert the string representation to an integer value
	while (i < digits)
	{
		if ((*(ptr + i) >= 48) && *(ptr + i) <= 57)
			result = (result * base) + (*(ptr + i) - 48);
		else if ((*(ptr + i) >= 65) && *(ptr + i) <= 90)
			result = (result * base) + (*(ptr + i) - 55);
		i++;
	}
	// Apply the sign to the result
	return (result * sign);
}