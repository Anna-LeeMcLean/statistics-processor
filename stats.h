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
 * @brief Header file for stats.c 
 *
 * Contains function declarations and descriptions for functions used
 * to analyze data in an array. Analysis includes finding the median,
 * mean, maximum and minimum of array data. 
 * 
 * @author Anna-Lee McLean
 * @date March 2, 2026
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Print all statistics of input array
 *
 * Prints minimum, maximum, mean and median of an input array to the standard output.
 *
 * @param arr Input array
 * @param size Number of elements in input array
 *
 * @return void
 */
void print_statistics(unsigned char* arr, unsigned int size);

/**
 * @brief Print array elements
 *
 * Prints all elements in input array to the standard output.
 *
 * @param arr Input array
 * @param size Number of elements in input array
 *
 * @return void
 */
void print_array(unsigned char*, unsigned int size);

/**
 * @brief Find the median value of array elements
 *
 * Calculates and returns the median of all elements in an input array.
 *
 * @param arr Input array
 * @param size Number of elements in input array
 *
 * @return The median of elements in the array
 */
unsigned char find_median(unsigned char* arr, unsigned int size);

/**
 * @brief Find the mean of array elements
 *
 * Calculates and returns the mean of all elements in an input array.
 *
 * @param arr Input array
 * @param size Number of elements in input array
 *
 * @return The mean of elements in the array
 */
unsigned char find_mean(unsigned char* arr, unsigned int size);

/**
 * @brief Find the maximum element in array
 *
 * Determines and returns the maximum element in an input array.
 *
 * @param arr Input array
 * @param size Number of elements in input array
 *
 * @return The maximum element in the array
 */
unsigned char find_maximum(unsigned char* arr, unsigned int size);

/**
 * @brief Find the minimum element in array
 *
 * Determines and returns the minimum element in an input array.
 *
 * @param arr Input array
 * @param size Number of elements in input array
 *
 * @return The minimum element in the array
 */
unsigned char find_minimum(unsigned char* arr, unsigned int size);

/**
 * @brief Sort elements in an array in descending order
 *
 * Sorts elements in an input array from largest to smallest.
 * Wrapper around stdlib qsort.
 *
 * @param arr Input array
 * @param size Number of elements in input array
 *
 * @return void
 */
void sort_array(unsigned char* arr, unsigned int size);


#endif /* __STATS_H__ */
