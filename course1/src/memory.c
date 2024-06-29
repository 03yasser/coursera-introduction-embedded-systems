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
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	// If the destination is greater than the source, copy the elements in reverse order
	if (dst > src)
	{
		i = length;
		while (i-- > 0)
			*(dst + i) = *(src + i);
	}
	else
	{
		i = 0;
		while (i < length)
		{
			*(dst + i) = *(src + i);
			i++;
		}
	}
	return (dst);
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	return (dst);
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	// Set each byte in the memory region to the specified value
	while (i < length)
	{
		*(src + i) = value;
		i++;
	}
	return (src);
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	size_t	i;

	i = 0;
	if (!src)
		return (NULL);
	// Set each byte in the memory region to zero
	while (i < length)
	{
		*(src + i) = 0;
		i++;
	}
	return (src);
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
	size_t		i;
	u_int8_t	temp;

	i = 0;
	if (!src)
		return (NULL);
	// Swap the elements in the first half with the corresponding elements in the second half
	while (i < length / 2)
	{
		temp = *(src + i);
        *(src + i) = *(src + length - i - 1);
        *(src + length - i - 1) = temp;
        i++;
	}
	return (src);
}

int32_t * reserve_words(size_t length)
{
	int32_t	*words;

	// Allocate memory for the array of 32-bit integers
	words = malloc(length * sizeof(int32_t));
	if (!words)
		return (NULL);
	return (words);
}

void free_words(int32_t * src)
{
	free(src);
}