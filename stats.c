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
 * @brief Implementation of data analysis library
 *
 * Implements functions which print and sort data, in addition to finding
 * their median, mean, maximum and minimum values.
 *
 * @author Anna-Lee McLean
 * @date March 2, 2026
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  print_array(test, SIZE);
  print_statistics(test, SIZE);

}

unsigned char find_median(unsigned char* arr, unsigned int size){

  if (arr == NULL) return 0;  // guard against null pointer

  sort_array(arr, size);

  unsigned char median;
  if ((size/2) % 2 == 0) 
    median = (arr[size/2] + arr[(size/2)-1]) / 2;
  else
    median = arr[size/2];

  return median;
}

unsigned char find_mean(unsigned char* arr, unsigned int size){

  if (arr == NULL) return 0;  // guard against null pointer

  unsigned int total = 0;

  for (int i=0; i<size; ++i){
    total += arr[i];
  }

  return total/size;
}

unsigned char find_maximum(unsigned char* arr, unsigned int size){

  if (arr == NULL) return 0;  // guard against null pointer

  unsigned char max = 0;  // initialize the maximum to be the smallest possible value for an unsigned char

  for (int i=0; i<size; ++i){
    if (arr[i] > max) max = arr[i];
  }

  return max;
}

unsigned char find_minimum(unsigned char* arr, unsigned int size){

  if (arr == NULL) return 0;  // guard against null pointer

  unsigned char min = UCHAR_MAX;  // initialize the minimum to be the largest possible value for an unsigned char

  for (int i=0; i<size; ++i){
    if (arr[i] < min) min = arr[i];
  }

  return min;
}

int comp(const void* a, const void* b){

  int arg1 = *(const unsigned char*)a;
  int arg2 = *(const unsigned char*)b;

  if (arg1 > arg2) return -1;
  if (arg1 < arg2) return 1;
  return 0;
}

void sort_array(unsigned char* arr, unsigned int size){

  if (arr == NULL){
    printf("array is NULL");  // guard against null pointer
    return;
  }

  qsort(arr, size, sizeof(arr[0]), comp);
}

void print_statistics(unsigned char* arr, unsigned int size){
  
  if (arr == NULL){
    printf("array is NULL");  // guard against null pointer
    return;
  }

  printf("median: %d\n", find_median(arr, size));
  printf("mean: %d\n", find_mean(arr, size));
  printf("maximum: %d\n", find_maximum(arr, size));
  printf("minimum: %d\n", find_minimum(arr, size));
}

void print_array(unsigned char* arr, unsigned int size){

  if (arr == NULL){
    printf("array is NULL");  // guard against null pointer
    return;
  }
  
  printf("data:\n");

  for (int i=0; i<size; ++i)
    printf("%d, ", arr[i]);
  
  printf("\n");
}
