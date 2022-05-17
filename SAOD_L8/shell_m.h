#pragma once
int* shell_m(int _array[], int size, int& compares, int& refers)
{
	compares = 0;
	refers = 0;
	int* a = new int[size];
	int temp{ 0 }, j{ 0 };
	int steps = log2(size) - 1;
	int* step_selec = new int[steps - 1];

	
	for (size_t i = 0; i < size; i++)
	{
		a[i] = _array[i];
	}

	for (size_t i = steps-1; i > 0; i--)
	{
		step_selec[i] = pow(2, i) - 1;
	}
	
	
	return a;
}