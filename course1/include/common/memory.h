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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

typedef unsigned char	uint8_t;
typedef unsigned long	size_t;
typedef signed int int32_t;

#ifndef NULL
#define NULL ((void*)0)
#endif
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves a block of memory from source to destination
 *
 * This function copies 'length' bytes from memory area 'src' to memory area 'dst'.
 * If 'dst' and 'src' overlap, copying is done in such a way that the original source
 * bytes in the overlapping region are not overwritten before being copied to the
 * destination. It handles overlapping of source and destination memory blocks by
 * copying bytes backwards from the end when necessary, ensuring that no data is
 * corrupted. If either 'dst' or 'src' is NULL, the function returns NULL.
 *
 * @param src Pointer to the source data array to move from
 * @param dst Pointer to the destination data array to move to
 * @param length Number of bytes to move
 *
 * @return Returns a pointer to the destination array 'dst'.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies memory from source to destination
 *
 * This function copies 'length' bytes from memory area 'src' to memory area 'dst'.
 * The memory areas should not overlap. Use my_memmove() if the memory areas do overlap.
 * If either 'dst' or 'src' is NULL, the function returns NULL to indicate an error.
 *
 * @param src Pointer to the source data array to copy from
 * @param dst Pointer to the destination data array to copy to
 * @param length Number of bytes to copy
 *
 * @return Returns a pointer to the destination array 'dst'.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets memory with a specified value
 *
 * This function fills the first 'length' bytes of the memory area pointed to by 'src'
 * with the byte value 'value'. Unlike memcpy() and memmove(), this function is used to set
 * memory rather than copy it. This function does not check for NULL pointer, as the behavior
 * is undefined if 'src' is NULL.
 *
 * @param src Pointer to the data array to be filled
 * @param length Number of bytes to set
 * @param value Value to be set in each byte of the memory area
 *
 * @return Returns a pointer to the memory area 'src'.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets all bytes in a memory area to zero
 *
 * This function fills the first 'length' bytes of the memory area pointed to by 'src'
 * with zeros. It is used to initialize or reset memory. This function does not check for
 * NULL pointer, as the behavior is undefined if 'src' is NULL.
 *
 * @param src Pointer to the memory area to be zeroed
 * @param length Number of bytes to set to zero
 *
 * @return Returns a pointer to the memory area 'src'.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses a sequence of bytes in memory
 *
 * This function reverses the order of the first 'length' bytes in the memory area pointed to by 'src'.
 * It swaps each byte with its counterpart from the end of the specified range. This function does not
 * check for NULL pointer, as the behavior is undefined if 'src' is NULL.
 *
 * @param src Pointer to the memory area to be reversed
 * @param length Number of bytes to reverse
 *
 * @return Returns a pointer to the memory area 'src'.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates memory for an array of integers
 *
 * This function allocates memory for an array of 'length' integers and returns a pointer
 * to the beginning of that memory block. The memory is not initialized. If the allocation
 * fails, it returns NULL.
 *
 * @param length The number of integers to allocate memory for
 *
 * @return Returns a pointer to the allocated memory, or NULL if the allocation fails.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees allocated memory
 *
 * This function frees the memory block pointed to by 'src', which must have been returned
 * by a previous call to malloc(), calloc(), or realloc(). If 'src' is NULL, no operation is
 * performed.
 *
 * @param src Pointer to the memory block to be freed
 */
void free_words(int32_t * src);
#endif /* __MEMORY_H__ */
