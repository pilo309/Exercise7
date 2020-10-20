#pragma comment(lib, "RaspberryPI.lib")
#include <stdio.h>
#include <stdlib.h>
#include <RaspberryDLL.h>
#include "Exercise7.2.h"
#
#define ARRAY_SIZE 12       



//definere arrays p� 12//I sidste uge lavede du et program hvor du opsamlede data fra
//temperatursensorer og fotoresistoren p� din Raspberry Pi.
//Du skal nu lave dette program om s�ledes :
//-Hver gang der er g�et et minut skal den st�rst og den mindste m�lte
//v�rdi bestemmes og middelv�rdien skal beregnes.
//- I stedet for at udskrive alle m�lte v�rdier p� sk�rmen, skal kun den
//st�rste, den mindste og middelv�rdien udskrives.
//NB!Brug det modul du lavede i exercise 7.1.

//I denne �velse skal du bruge din Raspberry Pi.
//Skriv et program som hvert 5. sekund m�ler temperaturen og lysintensiteten og
//gemmer de m�lte v�rdier i to arrays � temperaturen i et array og lysintensiteten i
//et andet array.
//Efter 60 sekunder skal de m�lte v�rdier udskrive p� sk�rmen.Herefter startes
//forfra med m�linger(hint 6A)

int main(void)
{
	if (!Open())
	{
		printf("Error with connection\n");
		exit(1);
	}

	printf("Connected to Raspberry Pi\n");
	// To do your code

	int ARRAY2[ARRAY_SIZE];        //definere vores 2 arrays
	int ARRAY1[ARRAY_SIZE];

	int maxTemp, maxLight, minTemp, minLight;
	double avgTemp, avgLight;


	while (1)
	{

		int minTempArray[ARRAY_SIZE] = { 0 };
		int maxTempArray[ARRAY_SIZE] = { 0 };
		int minLightArray[ARRAY_SIZE] = { 0 };
		int maxLightArray[ARRAY_SIZE] = { 0 };
		int avgTempArray[ARRAY_SIZE] = { 0 };
		int avgLightArray[ARRAY_SIZE] = { 0 };


		for (size_t i = 0; i < ARRAY_SIZE; i++)
		{
			for (size_t i = 0; i < ARRAY_SIZE; i++)
			{
				ARRAY1[i] = getTemperature();
				ARRAY2[i] = getIntensity();
				Wait(500);
			}

			maxTempArray[i] = maxValue(ARRAY1, ARRAY_SIZE);

			maxLightArray[i] = maxValue(ARRAY2, ARRAY_SIZE);

			minTempArray[i] = minValue(ARRAY1, ARRAY_SIZE);

			minLightArray[i] = minValue(ARRAY2, ARRAY_SIZE);

			avgTempArray[i] = average(ARRAY1, ARRAY_SIZE);

			avgLightArray[i] = average(ARRAY2, ARRAY_SIZE);

		}

		printf_s("\n\n Max Temperaturen er: \n");
		for (size_t i = 0; i < ARRAY_SIZE; i++)
			printf_s("%5.2d", maxTempArray[i]);

		printf_s("\n\nLysintensiteten er: \n");
		for (size_t i = 0; i < ARRAY_SIZE; i++)
			printf_s("%5.2d", maxLightArray[i]);

	}

	return 0;
}
