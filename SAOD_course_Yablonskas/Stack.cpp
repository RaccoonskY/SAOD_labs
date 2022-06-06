#include "Stack.h"
#include <iomanip>


void Stack::push(const int& count, const std::string& name)
{
	_ptr++;
	if (!is_full())
	{
		_mass[_ptr].set_data(name, count);
	}
	else
	{
		std::cout << "There is no enough space at stack! " << std::endl;
		_ptr--;
	}
}


void Stack::push(const std::string& name, const int& count)
{
	_ptr++;
	if (!is_full())
	{
		_mass[_ptr].set_data(name, count);
	}
	else
	{
		std::cout << "There is no enough space at stack! " << std::endl;
		_ptr--;
	}
}

void Stack::push(const SNode& node) {

	_ptr++;
	if (!is_full())
	{
		_mass[_ptr] = node;
	}
	else
	{
		std::cout << "There is no enough space at stack! " << std::endl;
		_ptr--;
	}


}


void Stack::pop()
{
	if (!is_empty())
	{
		_ptr--;
	}
	else
	{
		std::cout << "Stack is empty!" << std::endl;
	}

}

void Stack::init_stack(const int& size)
{
	if (_mass == nullptr)
	{
		_mass = new SNode[size];
		_size = size;
	}
}

void Stack::show()
{
	int id = _ptr;
	while (id != -1)
	{
		std::cout
			<< "\n|                |                                    |                  |                               |"
			<< "\n| Subprog. name: |"; std::cout << std::setw(35) << _mass[id].get_prog(); std::cout << " | Number of lines: |" <<
			std::setw(8) << _mass[id].get_words() <<std::setw(24)<< "|";
		std::cout
			<< "\n|________________|____________________________________|__________________|_______________________________|";
		id--;
	}
}


