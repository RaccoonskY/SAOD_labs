/// 31 - 23 2)Динамическая очередь 1)статических стеков. 
/// Программа (имя) - композиция модулей (имена)
/// модуль - композиция подпрограмм  (имя п\п (string), количество строк текста (int))
#include <iostream>
#include "menu.h"

enum Menu {
	MENU_INIT,
    MENU_SHOW,
	MENU_ADDGEN,
	MENU_ADDSUB,
	MENU_DEL,
	MENU_SUBDEL,
    MENU_READ,
    MENU_WRFL,
	MENU_EXIT

};



int main()
{
	DynQueue Queue = DynQueue();


    bool program = true;
    int chosen;


    std::ifstream fin;
    std::ofstream fout;

    std::string program_name;

    while (program)
    {
        std::cout
            << "\n_____________________________________";
        std::cout
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 0.Change name of your program.    |"
            << "\n| 1.Show current data.              |"
            << "\n| 2.Add new module data.            |"
            << "\n| 3.Add new subprogram data.        |"
            << "\n| 4.Delete module data.             |"
            << "\n| 5.Delete subprogram data.         |"
            << "\n| 6.Read data from file.            |"
            << "\n| 7.Write data to file.             |"
            << "\n| 8.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_INIT:
            Queue.mem_clear();
            std::cout << "Enter the name of program: ";
            std::cin >> program_name;
            Queue.set_pr_name(program_name);
            break;
        case MENU_SHOW:
            Queue.show();
            break;
        case MENU_ADDGEN:
            menu_add(Queue);
            break;
        case MENU_ADDSUB:
            menu_add_sub(Queue);
            break;
        case MENU_DEL:
            Queue.del_elem();
            break;
        case MENU_SUBDEL:
            menu_sub_del(Queue);
            break;
        case MENU_READ:
            Queue.mem_clear();
            fin.open("input.txt");
            Queue.ReadFile(fin);
            fin.close();
            break;
        case MENU_WRFL:
            fout.open("output.txt");
            Queue.WriteToFile(fout);
            fout.close();
            break;
        case MENU_EXIT:
            Queue.mem_clear();
            program = false;
            break;
        default:
            std::cout << "\nUnknown command";
            break;
        }

    }
    Queue.mem_clear();


    return 0;
}
