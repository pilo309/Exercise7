#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Exercise7.1.h"
#define MY_ARRAY_SIZE 20

int maxValue(int * ArrayPtr, const int SIZE)
{

	int max = *ArrayPtr;

	for (size_t i = 1; i < SIZE; i++)
	{
		ArrayPtr++;
		if (max < *ArrayPtr)
		{
			max = *ArrayPtr;
		}

	}

	return max;
}

int minValue(int * ArrayPtr, const int SIZE)
{
	int min = *ArrayPtr;

	for (size_t i = 1; i < SIZE; i++)
	{
		ArrayPtr++;
		if (min > * ArrayPtr)
		{
			min = *ArrayPtr;
		}

	}

	return min;
}

double average(int Array[], const int SIZE)
{
	
	int avg = 0;

	for (size_t i = 1; i < SIZE; i++)
	{
		avg += Array[i];
	}
		

		return (double) avg / SIZE;

}

void randArray(int Array [], const int SIZE)
{

	int tal;

	int min = 0;

	int max = 20;

	srand(time(0));

	for (size_t i = 0; i < SIZE; i++)
		Array[i] = rand() % ((max-min+1)+min);

}