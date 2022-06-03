#pragma once
#include <iostream>

int* select_m(int _array[], int size, int& compares, int& refers)
{
	compares = 0;
	refers = 0;
	int* a = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		a[i] = _array[i];
	}

	int temp = 0;
	int k = 0;
	 
	for (size_t i = 0; i < size; i++)
	{
		k = i;
		for (size_t j = i + 1; j < size; j++)
		{
			compares++;
			if (a[j] < a[k])
			{
				k = j;
			}
			
		}
		if (i != k)
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
			refers++;
		}
		
	}

	return a;
}

