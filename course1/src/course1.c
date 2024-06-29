/******************************************************************************
 * Copyright (C) 2024 by Yasser Boutslihghoi
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Yasser Boutslihghoi is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file course1.c
 * @brief Abstraction of various data manipulation operations
 *
 * This implementation file provides an abstraction of various data manipulation
 * operations such as integer to ASCII conversion, ASCII to integer conversion,
 * memory move, memory copy, memory set, and string reversal via function calls.
 *
 * @author Yasser Boutslihghoi
 * @date June 29, 2024
 *
 */

#include "platform.h"
#include "course1.h"
#include "memory.h"

int8_t test_data1()
{
	uint8_t ptr1[20];
	int32_t number;

	number = 1234;
	PRINTF("itoa : number = %d, lengh = %d, converted string = %s\n", number, my_itoa(number, ptr1, 10), ptr1);
	uint8_t ptr2[5] = "4321";
	PRINTF("atoi : ASCII represented string = %s, converted integer = %d\n", ptr2, my_atoi(ptr2, 4, 10));
	return (0);
}

int8_t test_data2()
{
	uint8_t ptr1[20];
	int32_t number;

	number = 1234;
	PRINTF("itoa : number = %d, lengh = %d, converted string = %s\n", number, my_itoa(number, ptr1, 2), ptr1);
	uint8_t ptr2[10] = "1010101";
	PRINTF("atoi : ASCII represented string = %s, converted integer = %d\n", ptr2, my_atoi(ptr2, 7, 2));
	return (0);
}

int8_t test_memmove1()
{
	uint8_t	dst[20];
	size_t	lenght;
	uint8_t	src[20] = "hello world";

	lenght = 7;
	PRINTF("memmove : source \"%s\", length = %zu, destination \"%s\"\n", src, lenght, my_memmove(src, dst, lenght));
	return (0);
}

int8_t test_memmove2()
{
	uint8_t	src[12] = "hello world";
	uint8_t	*dst = src + 5;
	size_t	lenght;

	lenght = 3;
	PRINTF("memmove : source \"%s\"," , src);
	PRINTF("length = %zu, destination \"%s\"\n", lenght, my_memmove(src, dst, lenght));
	return (0);	

}

int8_t test_memmove3()
{
    uint8_t src[20] = "hello world";
    uint8_t *dst = src - 5;
	size_t	lenght;

	lenght = 7;
	PRINTF("memmove : source \"%s\"," , src);
	PRINTF("length = %zu, destination \"%s\"\n", lenght, my_memmove(src, dst, lenght));
	return (0);
}

int8_t test_memcopy()
{
	uint8_t src[20] = "hello world";
	uint8_t dst[20] = "\0";

	PRINTF("Before memcpy: src = \"%s\", dst = \"%s\"\n", src, dst);
	my_memcopy(src, dst, 5);
	PRINTF("After memcpy: src = \"%s\", dst = \"%s\"\n", src, dst);
    return 0;
}

int8_t test_memset()
{
    uint8_t buffer[7];

    my_memset(buffer, 6, 82);
	my_memset(buffer, 5, 69);
	my_memset(buffer, 4, 83);
	my_memset(buffer, 2, 65);
	my_memset(buffer, 1, 89);
	buffer[6] = '\0';
	PRINTF("my name = \"%s\"\n", buffer);
	// my name
    return 0;
}

int8_t test_reverse()
{
	uint8_t str[20] = "hello world";

	PRINTF("before \"%s\" ", str);
    my_reverse(str, 11);
	PRINTF("after \"%s\"\n", str);
	return (0);
}

int8_t	course1()
{
	// test_data1();
	// test_data2();
	// test_memmove1();
	// test_memmove2();
	// test_memmove3();
	// test_memcopy();
	// test_memset();
	// test_reverse();
	return 0;
}
