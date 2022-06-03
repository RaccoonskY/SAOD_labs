#pragma once
#include <iostream>

int* shell_m(int _array[], int size, int& compares, int& refers)
{
	compares = 0;
	refers = 0;
	int* a = new int[size];
	int steps = log2(size) - 1;
	int cur_st = 0;
	int* selection_steps = new int[steps - 1];
	int temp, j = 0,l = 0;

	
	for (size_t i = 0; i < size; i++)
	{
		a[i] = _array[i];

	}

	std::cout << "STEPS: ";
	for (size_t i = steps - 1; i > 0; i--)
	{
		selection_steps[j] = pow(2, i) - 1;
		std::cout << selection_steps[j]<<" ";
		j++;
	}
	std::cout << "\n";




	for (int m = 0; m < steps; m++) //steps Ц число шагов группировки, m Ц номер шага
	{
		cur_st = selection_steps[m]; //выбор величины шага группировки из заданного массива
		for (size_t i = cur_st; i < size; i++) //сортировка вставками внутри каждой группы
		{
		/*	temp = a[i];
			j = i - cur_st;
			refers += 1;
			while (j >= 0 && temp < a[j])
			{
				a[j + cur_st] = a[j];
				j = j - cur_st;
				refers += 1;
				compares += 1;

			}
			compares += 1;
			a[j + cur_st] = temp;
			refers++;*/
			j = i - cur_st;
			while (j >= 0 && a[i] < a[j])
			{
				j = j - cur_st;
				compares++;
			}
			compares++;
			if (j + cur_st != i)
			{
				temp = a[i]; l = i - cur_st;
				refers++;
				while (l >= j+cur_st)
				{
					a[l + cur_st] = a[l]; l = l - cur_st;
					refers++;

				}
				a[j + cur_st] = temp;
				refers++;
			}
		}
		
	}
	refers = refers / 3;

	delete[] selection_steps;
	return a;
}

