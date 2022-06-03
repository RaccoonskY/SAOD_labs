#pragma once
#include "data_sets.h"
#include <iostream>




void nulling_mass(ListNode* mass[])
{
	for (int i = 0; i < 10; i++)
	{
		if (mass[i] != nullptr)
		{
			delete mass[i];
			mass[i] = nullptr;
		}
	}
}

void show_by_ten(ListNode* mass[])
{
	ListNode* temp;
	for (int i = 0; i < 10; i++)
	{

		temp = mass[i];
		while (temp != nullptr)
		{
			std::cout << " " << (temp->_item).key << '(' << (temp->_item).inf << ')';
			temp = temp->_next;
		}
		std::cout << '\n';
	}

}
void mem_clear_by_ten(ListNode* mass[])
{
	ListNode* temp;
	ListNode* next;
	for (int i = 0; i < 10; i++)
	{
		temp = mass[i];
		while (temp != nullptr)
		{
			next = temp->_next;
			delete temp;
			temp = next;

		}
		mass[i] = nullptr;
	}
}


Item* union_lists(ListNode* mass[], const int& size)
{
	Item* new_items = new Item[size];
	ListNode* temp_node;
	int j = 0;
	temp_node = mass[j];
	for (int i = 0; i < size; i++)
	{
		
		if (temp_node == nullptr)
		{
			j++;
			temp_node = mass[j];
			new_items[i] = temp_node->_item;
			temp_node = temp_node->_next;
		}
		else
		{
			new_items[i] = temp_node->_item;
			temp_node = temp_node->_next;
		}
	}
	return new_items;
}

Item* grading_sort(Item items[], const int& size, const int& grade, int& compares, int& refs)
{
	compares = 0;
	refs = 0;
	int selected_key;
	int ten_val;
	ListNode* temp_node;
	ListNode* last_node;
	ListNode* mass[10];
	Item* _items = new Item[size];


	for (size_t i = 0; i < size; i++)
	{
		_items[i] = items[i];
	}

	for (int i = 0; i < 10; i++)
	{
		mass[i] = nullptr;
	}

	for (int i = 0; i < grade; i++)
	{
		ten_val = pow(10, i);
		for (int j = 0; j < size; j++)
		{	
			selected_key = _items[j].key / ten_val  % 10;
			if (mass[selected_key] == nullptr)
			{
				temp_node = new ListNode();
				temp_node->_item = _items[j];
				mass[selected_key] = temp_node;
				refs++;

			}
			else
			{
				last_node = mass[selected_key];
				while (last_node->_next != nullptr)
				{
					last_node = last_node->_next;
				}
				temp_node = new ListNode();
				temp_node->_item = _items[j];
				last_node->_next = temp_node;
				refs++;
			}
		}
		delete[] _items;
		_items = union_lists(mass, size);
		mem_clear_by_ten(mass);
	}
	return _items;

}

