#pragma once
#include <iostream>

void quicksort_am(int _array[] ,int left, int right, int& compares, int& refers)
{
	int temp, medi, i, j;

	i = left;
	j = right;
	int m = (left + right) / 2;
	medi = _array[m];
	refers += 4;
	do
	{
		while (_array[i] < medi) { i++; refers++; compares++; }
		while (_array[j] > medi) { j--; refers++; compares++; }
		compares += 2;
		if (i <= j)
		{
			temp = _array[i];
			_array[i] = _array[j];
			_array[j] = temp;
			i++;
			j--;
			refers += 4;
		}
		compares++;

	} while (!(i>j));

	compares+=2;
	if (left < j) quicksort_am(_array, left, j, compares, refers);
	if (i < right) quicksort_am(_array, i, right, compares, refers);
}

