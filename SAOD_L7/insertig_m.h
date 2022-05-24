#pragma once
#include <iostream>

int* inserting_m(int _array[], int size, int& compares, int& refers)
{
	compares = 0;
	refers = 0;
	int* arr = new int[size];
	int temp = 0;
	int j = 0;
    int l;


	for (size_t i = 0; i < size; i++)
	{
		arr[i] = _array[i];
	}


    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while (j >= 0 && arr[i] < arr[j])
        {
            j -= 1;
            compares++;
        }
        compares++;
        if (j + 1 != i)
        {
            temp = arr[i];
            l = i - 1;
            refers++;
            while (l >= j + 1)
            {
                arr[l + 1] = arr[l]; l--;
                refers++;
            }
            arr[j + 1] = temp;
            refers++;
        }
    }
    refers = refers / 3;
	

	return arr;
}

