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
	int j,k = 0;
	for (size_t i = 0; i < size-1; i++)
	{
		temp = a[i];
		j = i - 1;
		k = i;
		refers += 1;

		for (j = i+1; j < size; j++)
		{
			if (a[j] < temp)
			{
				k = j;
				temp = a[j];
				refers += 1;
			}
			compares += 1;
		}


		a[k] = a[i];
		a[i] = temp;
		refers += 2;
	}

	return a;
}

