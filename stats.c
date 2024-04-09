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
 * @file stats.c
 * @brief week 1 Assignment
 *
 * This file includes all the required functions implementations in the week1 assignmentd
 *
 * @author yasser boutslighoi
 * @date 2024-04-09
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() 
{
	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
								114, 88,   45,  76, 123,  87,  25,  23,
								200, 122, 150, 90,   92,  87, 177, 244,
								201,   6,  12,  60,   8,   2,   5,  67,
								7,  87, 250, 230,  99,   3, 100,  90};
	unsigned char minimum;
	unsigned char maximum;
	float mean;
	float median;

	printf("Array before sorting: \n");
	print_array(test, SIZE);
	median = find_median(test, SIZE);
	mean = find_mean(test, SIZE);
	maximum = find_maximum(test, SIZE);
	minimum = find_minimum(test, SIZE);
	print_statistics(minimum, maximum, mean, median);
	sort_array(test, SIZE);
	printf("Array after sorting: \n");
	print_array(test, SIZE);

}

void	print_statistics(unsigned char minimum, unsigned char maximum, float mean, float median)
{
	printf("Minimum: %u\n", minimum);
	printf("Maximum: %u\n", maximum);
	printf("Mean: %.2f\n", mean);
	printf("Median: %.2f\n", median);
}

void	print_array(unsigned char *array, unsigned int length)
{
	// Check if the array is not null
	if (!array)
		return ;
	for(int i = 0; i < length; i++)
		printf("%d|", array[i]);
	printf("\n");
}

float	find_median(unsigned char *array, unsigned int length)
{
	float	median;

	// Check if the array is not null
	if (!array)
		return (0);
	sort_array(array, length);
	// If the length of the array is odd
	if (length % 2 == 1)
		median = array[length / 2]; // The median is the middle element
	else
	{
		// If the length is even, the median is the average of the two middle elements
		median = (array[length / 2 - 1] + array[length / 2]);
		median /= 2;
	}
	return (median);
}

float	find_mean(unsigned char *array, unsigned int length)
{
	float	mean; // Variable to store the mean value

	// Check if the array is not null
	if (!array)
		return (0);
	mean = 0;
	for (int i = 0; i < length; i++)
		mean += array[i];// Add the current element to the mean
	// Divide the total by the number of elements to get the mean
	mean = mean / length;
	return (mean);
}

unsigned char	find_maximum(unsigned char *array, unsigned int length)
{
	unsigned char	max;

	// Check if the array is not null
	if (!array)
		return (0);
	// Initialize the maximum to the first element of the array
	max = *array;
	for (int i = 0; i < length; i++)
	{
		// If the current element is greater than the maximum, update the maximum	
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

unsigned char	find_minimum(unsigned char *array, unsigned int length)
{
	unsigned char	min;

	// Check if the array is not null
	if (!array)
		return (0);
	// Initialize the minimum to the first element of the array
	min = *array;
	for (int i = 0; i < length; i++)
	{
		// If the current element is less than the minimum, update the minimum
		if (min > array[i])
			min = array[i];
	}
	return (min);
}

void	sort_array(unsigned char *array, unsigned int length)
{
	unsigned char	tmp;

	// Check if the array is not null
	if (!array)
		return ;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}