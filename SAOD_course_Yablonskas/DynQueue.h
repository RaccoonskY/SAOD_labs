#pragma once
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>


class DynQueue;

class QNode
{
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
	Stack* get_stack() { return &_stack; }
	std::string get_name() { return _name; }
	void set_next(QNode* next) { _next = next; }
	QNode* get_next() { return _next; }
	void show_stack() { _stack.show(); }
	
};




class DynQueue
{

private:

	std::string program_name;
	QNode* _first = nullptr;
	QNode* _last = nullptr;


public:

	DynQueue()
	{
		_first = new QNode();
		_last = _first;
	}



	QNode* get_first() { return _first; }
	QNode* get_last() { return _last; }
	void set_first(QNode n_first) { *_first = n_first; }
	void set_last(QNode n_second) { *_last = n_second; }
	std::string get_pr_name() { return program_name; }
	void set_pr_name(const std::string& n_name) { program_name = n_name; }


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
		int w_space_pr_name = (88 - program_name.size()) / 2 + program_name.size();
		int w_space_md_name;
		std::cout
			<< "\n__________________________________________________________________________________________________________"
			<< "\n|                |                                                                                       |"
			<< "\n| Program name:  |"; std::cout << std::setw(w_space_pr_name) << program_name; std::cout << std::setw(88 - w_space_pr_name) << "|";
		std::cout
			<< "\n|________________|_______________________________________________________________________________________|";

		while (qTemp != nullptr)
		{
			w_space_md_name = (88 - qTemp->get_name().size()) / 2 + qTemp->get_name().size();
			std::cout
				<< "\n|                |                                                                                       |"
				<< "\n| Module name:   |"; std::cout << std::setw(w_space_md_name) << qTemp->get_name(); std::cout << std::setw(88 - w_space_md_name) << "|";
			std::cout
				<< "\n|________________|_______________________________________________________________________________________|";
			qTemp->show_stack();
			qTemp = qTemp->get_next();
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
			QNode* qTemp = _first->get_next();
			_first->set_next(qTemp->get_next());
			if (_first->get_next() == nullptr)
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
				if (pTemp->get_name() == modul)
				{
					std::cout << "\nModule " << modul << " is found! ";
					return pTemp;
				}
				pTemp = pTemp->get_next();
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
			pTemp->get_stack()->push(name, count);
		}

	}

	void pop(std::string module_name)
	{
		QNode* pTemp = search(module_name);
		if (pTemp != nullptr)
		{
			pTemp->get_stack()->pop();
		}
	}


	void mem_clear()
	{	
		program_name = "";
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

		std::string str;
		std::string prog_name, mod_name, stack_size, sub_name, str_words;
		Stack* temp_stack = nullptr;
		int mod_size = 0;
		int st_size, words;
		int name_counts = 0;

		while (!fin.eof())
		{
			getline(fin, str);
			if (str=="")
			{
				continue;
			}
			else
			{
				if (program_name == "" && name_counts == 0)
				{
					mod_size = 0;
					prog_name = "";
					while (str[mod_size] != '#')
					{
						prog_name.push_back(str[mod_size]);
						mod_size++;
					}
					if (prog_name != "")
					{
						set_pr_name(prog_name);
						name_counts++;
					}

				}
				else
				{
					mod_name = "";
					stack_size = "";
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
					if (str == "")
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
						} while (str[mod_size += 1] != ' ');
						data_trade(temp_stack, mod_name);
						delete temp_stack;
						temp_stack = nullptr;
					}
				}
			}	
		}
	}

	void WriteToFile(std::ofstream& fout) {
		QNode* qTemp = _first->get_next();
		bool name_is_written = false;
		int id;
		while (qTemp != nullptr)
		{
			if (!name_is_written)
			{
				fout << program_name << "#\n";
				name_is_written = true;
			}
			fout << qTemp->get_name() <<"("<<(qTemp->get_stack())->get_size()<<"):\n";
			std::cout<< qTemp->get_name() << "(" << (qTemp->get_stack())->get_size() << "):\n";
			id = qTemp->get_stack()->get_ptr();
			while (id != -1)
			{
				fout<< "P:" << qTemp->get_stack()->get_mass()[id].get_prog() << " W:" << qTemp->get_stack()->get_mass()[id].get_words() << ";";
				std::cout<<"P:" << qTemp->get_stack()->get_mass()[id].get_prog() << " W:" << qTemp->get_stack()->get_mass()[id].get_words() << ";";
				id--;
			}
			fout <<" "<< std::endl;
			qTemp = qTemp->get_next();
		}
		std::cout << "\nData is successfully written to file!";

	}


};

