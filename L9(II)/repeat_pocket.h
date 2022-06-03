#pragma once
#include <iostream>
#include "data_sets.h"




void show(ListNode* mass[], const int& size)
{
	ListNode* temp;
	for (int i = 0; i < size; i++)
	{
		temp = mass[i];
		if (mass[i] != nullptr)
		{
			while (temp != nullptr)
			{
				std::cout << " " << (temp->_item).key << '(' << (temp->_item).inf << ')';
				temp = temp->_next;
			}
			std::cout << "\n";
		}
	}
}


void repeat_pocket(Item items[], ListNode* mass[], const int& size,int& compares, int& refs)
{
	compares = 0;
	refs = 0;
	Item tempit;
	ListNode* temp_node;
	ListNode* last_node;

	for (int i = 0; i < size; i++)
	{
		tempit = items[i];
		if (mass[tempit.key] == nullptr)
		{
			temp_node = new ListNode();
			temp_node->_item = tempit;
			mass[tempit.key] = temp_node;
			refs++;

		}
		else
		{
			last_node = mass[tempit.key];
			refs++;
			while (last_node->_next != nullptr)
			{
				last_node = last_node->_next;
			}
			temp_node = new ListNode();
			temp_node->_item = tempit;
			last_node->_next = temp_node;
		}
	}

}

void mem_clear(ListNode* mass[], const int& size)
{
	for (int i = 0; i < size; i++)
	{

		delete mass[i];
		mass[i] = nullptr;

	
	}
}