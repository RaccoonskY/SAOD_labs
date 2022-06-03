#pragma once
#include <iostream>
#include "data_sets.h"

Item* simple_pocket(Data* data, int size, int& compares, int& refers)
{
	compares = 0;
	refers = 0;
	Item* _array = new Item[size];
	Item* _mass = data->_array;


	for (int i = 0; i < size; i++)
	{
		_array[_mass[i].key] = _mass[i];
	}

	return _array;
	
}



Item* simple_pocket2(Data* data, int size, int& compares, int& refers)
{
	compares = 0;
	refers = 0;
	Item* _array = new Item[size];
	Item* _mass = data->_array;
	Item temp;

	for (size_t i = 0; i < size; i++)
	{
		_array[i] = _mass[i];
	}

	for (int i = 0; i < size; i++)
	{
		compares++;
		while (_array[i].key != i)
		{
			compares++;
			temp = _array[i];
			_array[i] = _array[temp.key];
			_array[temp.key] = temp;
			refers += 1;
		}
	}	

	return _array;
}
