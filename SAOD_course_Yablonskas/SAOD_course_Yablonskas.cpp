/// 31 - 23 2)Динамическая очередь 1)статических стеков. 
/// Программа (имя) - композиция модулей (имена)
/// модуль - композиция подпрограмм  (имя п\п (string), количество строк текста (int))


#include <iostream>
#include "DynQueue.h"


void menu_add(DynQueue& queue)
{
    std::string name;
    int size;
    std::cout << "Enter name of module: ";
    std::cin >> name;
    std::cout << "Enter the number of subprograms: ";
    std::cin >> size;
    queue.add_elem(size, name);

}

void menu_add_sub(DynQueue& queue)
{
    std::string subp_name, modul;
    int count;
    std::cout << "Enter the module name: ";
    std::cin >> modul;
    std::cout << "Enter the subprogram name: ";
    std::cin >> subp_name;
    std::cout << "Enter the count of rows: ";
    std::cin >> count;
    queue.push(modul, subp_name, count);
}

void menu_sub_del(DynQueue& queue)
{
    std::string modul;
    std::cout << "Enter the module name: ";
    std::cin >> modul;
    queue.pop(modul);
}

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
    int choice;
    std::ifstream fin;
    std::ofstream fout;

    while (program)
    {
        std::cout
            << "\n_____________________________________";
        std::cout
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 0.Initialise dynamic queue.       |"
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
        case MENU_EXIT:
            Queue.mem_clear();
            program = false;
            break;
        case MENU_READ:
            fin.open("input.txt");
            Queue.mem_clear();
            Queue.ReadFile(fin);
            fin.close();
            break;
        case MENU_WRFL:
            fout.open("output.txt");
            Queue.WriteToFile(fout);
            fout.close();
            break;
        default:
            std::cout << "\nUnknown command";
            break;
        }

    }



    return 0;
}
