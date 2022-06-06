#pragma once
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
    while (!std::isdigit(size))
    {
        std::cout << "You must enter a number!";
        std::cin >> size;
    }
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
    while (!std::isdigit(count))
    {
        std::cout << "You must enter a number!";
        std::cin >> count;
    }
    queue.push(modul, subp_name, count);
}

void menu_sub_del(DynQueue& queue)
{
    std::string modul;
    std::cout << "Enter the module name: ";
    std::cin >> modul;
    queue.pop(modul);
}
