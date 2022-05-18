#pragma once
#include <iostream>


void pyr_select(int _array[], int al, int ar, int& compares, int& refers)
{
	int x, i, j;
	i = al;
	j = 2 * al;
	x = _array[al];
	refers += 3;

	if (j < ar && _array[j + 1] > _array[j]) j++; refers++; compares+=2;
	while (j <= ar && _array[j] > x)
	{
		_array[i] = _array[j];
		i = j;
		j = 2 * j;
		
		if (j < ar && _array[j + 1] > _array[j]) j++; refers++; compares+=2;

		refers += 2;
		compares += 2;
		compares += 2;
	}
	compares += 2;
	_array[i] = x;
	refers++;
}




void pyramid_am(int _array[], int size, int& compares, int& refers)
{
	int left, right,temp;
	left = size / 2 + 1;
	right = size;
	refers += 2;
	while (left> 0)
	{
		left = left - 1;
		pyr_select(_array, left, right, compares, refers);
		compares++;
		refers++;
	}
	while (right>0)
	{
		temp = _array[0];
		_array[0] = _array[right];
		_array[right] = temp;
		right--;
		pyr_select(_array, left, right, compares, refers);

		refers += 3;
		compares++;

	}
	compares += 2;
}

