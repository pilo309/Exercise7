#include <stdio.h>
#include "Exercise7.1.h"
#define MY_ARRAY_SIZE 20

//Alle tre funktioner skal kunne ”modtage” et array og de skal kunne bestemme
//hhv.den største værdi i arrayet, den mindste værdi i arrayet og gennemsnittet af 
//alle værdier i arrayet(Hint 7A).
//NB!Grunden til, at der er forskel på parameterlisten i funktionerne, er, at du
//skal prøve begge dele .
//Skriv derefter et lille testprogram(main) hvori du tester dine funktioner.



int main(void)
{
	int RandomArray[MY_ARRAY_SIZE];			//initialisere array
	int max, min;
	double avg;

	randArray(RandomArray, MY_ARRAY_SIZE);

	for (size_t i = 1; i<MY_ARRAY_SIZE; i++)
	{
		printf_s("%d\n", RandomArray[i]);
	}

	puts("");

	max = maxValue(RandomArray, MY_ARRAY_SIZE);	
	printf_s("Max value is %d\n", max);
	
	min = minValue(RandomArray, MY_ARRAY_SIZE);
	printf_s("Min value is %d\n", min);

	avg = average(RandomArray, MY_ARRAY_SIZE);
	printf_s("Average value is %f\n", avg);

	return 0;
}