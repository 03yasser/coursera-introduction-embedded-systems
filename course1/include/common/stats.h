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
 * @file stats.h
 * @brief  Declarations and macros required for the week1 assignment
 *
 *
 * @author yasser boutslighoi
 * @date 2024-04-09
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void	print_statistics(unsigned char minimum, unsigned char maximum, float mean, float median);
/**
 * @brief Prints the statistics of a data set
 *
 * This function takes the minimum, maximum, mean, and median of a data set as input, and prints these statistics. 
 *
 * @param minimum The minimum value of the data set
 * @param maximum The maximum value of the data set
 * @param mean The mean value of the data set
 * @param median The median value of the data set
 *
 * @return This function does not return a value
 */

void	print_array(unsigned char *array, unsigned int length);
/**
 * @brief Prints the elements of the given array
 *
 * This function takes an array and its length as input, and prints each element of the array. 
 *
 * @param array The array to be printed
 * @param length The number of elements in the array
 *
 * @return This function does not return a value
 */

float	find_median(unsigned char *array, unsigned int length);
/**
 * @brief Finds the median of the given array
 *
 * This function takes an array and its length as input, and returns the median value. 
 *
 * @param array The array to find the median of
 * @param length The number of elements in the array
 *
 * @return The median value of the array
 */

float	find_mean(unsigned char *array, unsigned int length);
/**
 * @brief Finds the mean of the given array
 *
 * This function takes an array and its length as input, and returns the mean value. 
 *
 * @param array The array to find the mean of
 * @param length The number of elements in the array
 *
 * @return The mean value of the array
 */

unsigned char	find_maximum(unsigned char *array, unsigned int length);
/**
 * @brief Finds the maximum value of the given array
 *
 * This function takes an array and its length as input, and returns the maximum value. 
 *
 * @param array The array to find the maximum value of
 * @param length The number of elements in the array
 *
 * @return The maximum value of the array
 */

unsigned char	find_minimum(unsigned char *array, unsigned int length);
/**
 * @brief Finds the minimum value of the given array
 *
 * This function takes an array and its length as input, and returns the minimum value. 
 *
 * @param array The array to find the minimum value of
 * @param length The number of elements in the array
 *
 * @return The minimum value of the array
 */

void	sort_array(unsigned char *array, unsigned int length);
/**
 * @brief Sorts the elements of the given array
 *
 * This function takes an array and its length as input, and sorts the array in place. 
 *
 * @param array The array to be sorted
 * @param length The number of elements in the array
 *
 * @return This function does not return a value
 */

#endif /* __STATS_H__ */
