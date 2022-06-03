#pragma once
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <ostream>


class DynQueue;

class QNode
{
	friend class DynQueue;
private:
	Stack _stack;
	std::string _name;

	QNode* _next = nullptr;
public:
	QNode()
	{

	}

	QNode(const int& size,std::string name, QNode* next): _name(name),_next(next)
	{
		_stack.init_stack(size);

	};
	
	void init_stack(const int& size) { _stack = Stack(size); }
	Stack get_stack() { return _stack; }
	std::string get_name() { return _name; }
	void set_next(QNode* next) { _next = next; }
	QNode* get_next() { return _next; }
	void show_stack() { _stack.show(); }
	void add_to_stack() {
		_stack.data_stack();
	}
};




class DynQueue
{
	friend class QNode;
private:


	QNode* _first = nullptr;
	QNode* _last = nullptr;


public:

	DynQueue()
	{
		_first = new QNode();
		_last = _first;
	}

	DynQueue(const int& size,const std::string& name = "", QNode * next = nullptr)
	{
		_first = new QNode(size,"", next);
		_last = _first;

	}

	bool is_empty()
	{

		if (_first->get_next() == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void show()
	{
		QNode* qTemp = _first->get_next();
		
		while (qTemp != nullptr)
		{
			std::cout << "Module name: "<<qTemp->_name<<"\n Subprograms: ";
			qTemp->show_stack();
			qTemp = qTemp->_next;
		}
		std::cout << std::endl;

	}


	void add_elem(const int& size, const std::string& name)
	{
		QNode* qTemp = new QNode(size, name, nullptr);
		_last->set_next(qTemp);
		_last = qTemp;
	}
	

	void del_elem()
	{
		if (!is_empty())
		{
			QNode* qTemp = _first->_next;
			_first->_next = qTemp->_next;
			if (_first->_next == nullptr)
			{
				_last = _first;
			}
			delete qTemp;
		}
		else
		{
			std::cout << "Queue is empty!\n";
		}

	}

	QNode* search(std::string modul)
	{
		if (!is_empty())
		{
			QNode* pTemp = _first->get_next();
			while (pTemp != nullptr)
			{
				if (pTemp->_name == modul)
				{
					std::cout << "\nModul " << modul << " is found! ";
					return pTemp;
				}
				pTemp = pTemp->_next;
			}
			std::cout << "There is no such module!\n";
			return nullptr;

		}
		else
		{
			std::cout << "Queue is empty!\n";
			return nullptr;
		}
	}

	void push(std::string module_name, const std::string& name, const int& count)
	{

		QNode* pTemp = search(module_name);
		if (pTemp != nullptr)
		{
			pTemp->_stack.push(name, count);
		}

	}

	void pop(std::string module_name)
	{
		QNode* pTemp = search(module_name);
		if (pTemp != nullptr)
		{
			pTemp->_stack.pop();
		}
	}


	void mem_clear()
	{	
		while (!is_empty())
		{
			del_elem();
		}
		
	}

	void data_trade(Stack*& tr_stack, std::string module_name)
	{
		int id = tr_stack->get_ptr();
		SNode* temp_mass = tr_stack->get_mass();
		while (id != -1)
		{
			push(module_name, temp_mass[id].get_prog(), temp_mass[id].get_words());
			id--;
		}
	}
	void ReadFile(std::ifstream& fin)
	{

		std::string str, next;
		std::string mod_name, stack_size, sub_name, str_words;
		Stack* temp_stack = nullptr;
		int mod_size = 0;
		int st_size, words;

		while (!fin.eof())
		{
			getline(fin, str);
			if (str=="")
			{
				continue;
			}
			else
			{
				mod_name = "";
				mod_size = 0;
				while (str[mod_size] != '(')
				{
					mod_name.push_back(str[mod_size]);
					mod_size++;
				}
				mod_size++;
				while (str[mod_size] != ')')
				{
					stack_size.push_back(str[mod_size]);
					mod_size++;
				}
				if (stack_size != "")
				{
					st_size = std::stoi(stack_size);
					add_elem(st_size, mod_name);
				}
				getline(fin, str);
				if (str=="")
				{
					continue;
				}
				else
				{
				
					temp_stack = new Stack(st_size);
					mod_size = 0;
					do
					{
						mod_size += 2;
						sub_name = "";
						str_words = "";
						while (str[mod_size] != ' ')
						{
							sub_name.push_back(str[mod_size]);
							mod_size++;
						}
						mod_size += 3;
						while (str[mod_size] != ';')
						{
							str_words.push_back(str[mod_size]);
							mod_size++;
						}
						if (str_words != "")
						{
							words = std::stoi(str_words);
							temp_stack->push(words, sub_name);
						}
					} while (str[mod_size+=1] != ' ');
					data_trade(temp_stack, mod_name);
					delete temp_stack;
					temp_stack = nullptr;
				}
			}	


		}
	}

	void WriteToFile(std::ofstream& fout) {
		QNode* qTemp = _first->get_next();
		int id;
		while (qTemp != nullptr)
		{
			fout << qTemp->_name <<"("<<qTemp->_stack.get_size()<<"):\n";
			id = qTemp->_stack.get_ptr();
			while (id != -1)
			{
				fout<< "P:" << qTemp->_stack.get_mass()[id].get_prog() << " W:" << qTemp->_stack.get_mass()[id].get_words() << ";";
				id--;
			}
			fout <<" "<< std::endl;
			qTemp = qTemp->_next;
		}
		std::cout << "\nData is successfully written to file!";

	}


};

