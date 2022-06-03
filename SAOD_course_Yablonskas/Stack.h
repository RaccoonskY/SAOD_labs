#pragma once
#include <iostream>
#include <string>


class SNode
{
private:
	std::string _subprogramm;
	int _words = 0;
public:

	SNode()
	{

	}
	
	SNode(const std::string& name, const int& count): _subprogramm(name), _words(count)
	{

	}

	std::string get_prog() { return _subprogramm; }
	int get_words() { return _words; }
	void set_prog(std::string name) { _subprogramm = name; }
	void set_words(const int& count) { _words = count; }
	void set_data(const std::string& name, const int& words) { _subprogramm = name, _words = words; }
	void set_data(const int& words, const std::string& name) { _subprogramm = name, _words = words; }

};




class Stack
{
private:
	SNode* _mass = nullptr;
	int _ptr = -1;
	int _size = 10;

public:
	Stack()
	{

	}
	
	Stack(const int& size): _size(size)
	{
		_mass = new SNode[size];
	}


	bool is_full() { return (_ptr == _size); }
	bool is_empty() { return (_ptr == -1); }
	void push(const std::string& name, const int& count);
	void push(const int& count, const std::string& name);
	void push(const SNode& node);
	void pop();
	void show();
	int get_words() { return _mass->get_words(); }
	std::string get_subprog(){ return _mass->get_prog(); }
	int get_ptr() { return _ptr; }
	SNode* get_mass() { return _mass; }
	int get_size() { return _size; }

	void data_stack() {
		std::string name;
		int count;
		for (size_t i = 0; i < _size; i++)
		{
			std::cout << "Enter name of subprogramm:";
			std::cin >> name;
			std::cout << "Enter the number of rows:";
			std::cin >> count;
			push(name, count);
		}
	}



	void init_stack(const int& size) {
		if (_mass == nullptr)
		{
			_mass = new SNode[size];
			_size = size;
		}
	}




	~Stack()
	{
		delete[] _mass;
	}
};

