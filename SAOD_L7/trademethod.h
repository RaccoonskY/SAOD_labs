#pragma once
#include <iostream>


int* trade_method(int array[], int size, int& compares, int& refers )
{
	compares = 0;
	refers = 0;
	int* _array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		_array[i] = array[i];
	}

	int temp = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size-1; j > i ;j--)
		{
			if (_array[j-1]>_array[j])
			{
				temp = _array[j - 1];
				_array[j - 1] = _array[j];
				_array[j] = temp;
				refers += 3;
			}
			compares += 1;
		}

	}
	refers = refers / 3;
	return _array;
}



