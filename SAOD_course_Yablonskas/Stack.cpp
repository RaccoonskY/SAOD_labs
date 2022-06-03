#include "Stack.h"


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


void Stack::show()
{
	int id = _ptr;
	while (id != -1)
	{
		std::cout << "Programm: " << _mass[id].get_prog() << " Words: " << _mass[id].get_words() << " |";
		id--;
	}
	std::cout<<std::endl;
}


