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
 * @file <stats> 
 * @brief <A small program on oerations on an given array>
 *
 * 
 *
 * @author <HARISH.A.R>
 * @date <05/02/2023>
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  int compare(const void *a, const void *b)
   {
    unsigned char x = *(unsigned char*)a;
    unsigned char y = *(unsigned char*)b;
    return y - x;
  }
  int len;
  unsigned char arr[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

len=sizeof(arr)/sizeof(arr[0]);
printf("Length of the array= %d\n",len);

qsort(arr, len, sizeof(unsigned char), compare);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int mid = len / 2;
    unsigned char median;
    if (len % 2 == 0) {
        median = (arr[mid - 1] + arr[mid]) / 2;
    } else {
        median = arr[mid];
    }

    printf("Median: %d\n", median);

  unsigned char max = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Max: %d\n", max);
  
  unsigned char min=255;
   for (int i = 0; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Min: %d\n", min);
  
  unsigned int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }

    float mean = (float)sum / len;

    printf("Mean: %f\n", mean);

  printf("Finalized Array after all operations and sorting done: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
     printf("\n");
}
