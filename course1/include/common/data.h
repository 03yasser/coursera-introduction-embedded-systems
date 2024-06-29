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
 * @file data.h
 * @brief Abstraction of data conversion operations
 *
 * This header file provides an abstraction of converting data between
 * integer and string representations via function calls. 
 *
 * @author yasser boutslighoi 
 * @date June 23, 2024
 *
 */

#ifndef DATA_H
#define DATA_H

typedef unsigned char	uint8_t;
typedef unsigned long	size_t;
typedef signed int		int32_t;
typedef unsigned int	uint32_t;


/**
 * @brief Converts an integer to a string
 *
 * Given an integer, a pointer to a uint8_t data set, and a base, this function will convert the integer to a string representation in the given base and store it in the data set.
 *
 * @param data The integer to convert
 * @param ptr Pointer to the data array where the string representation will be stored
 * @param base The base to use for the string representation
 *
 * @return uint8_t Returns the length of the converted data.
 */
uint8_t	my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts a string to an integer
 *
 * Given a string, the number of digits in the string, and a base, this function will convert the string representation of the number in the given base to an integer.
 *
 * @param ptr Pointer to the string representation of the number
 * @param digits The number of digits in the string
 * @param base The base of the string representation
 *
 * @return int32_t Returns the converted integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */