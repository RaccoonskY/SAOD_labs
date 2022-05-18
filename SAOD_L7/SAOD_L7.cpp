#include <iostream>
#include <ctime>
#include "trademethod.h"
#include "insertig_m.h"
#include "select_m.h"


struct Data
{
    int* _array;
    int _size;

    Data(int size) : _size(size)
    {
        _array = new int[size];
    }

};

int rand_int() {

    int randi = 0 + rand() % 100;
    return randi;

}

void rand_init(Data*& data)
{
    for (int i = 0; i < data->_size; i++)
    {
        data->_array[i] = rand_int();
    }
}

void show(const int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << '_' << array[i];
    }
}

void mem_clear(Data*& data)
{
    delete data->_array;
    delete data;
}

enum Menu {
    MENU_INIT,
    MENU_SHOW,
    MENU_TRADE,
    MENU_INSERT,
    MENU_SELECT,
    MENU_EXIT

};

int main()
{
    srand(time(0));
 
    Data* data_set = nullptr;
    int* sorted_ar = nullptr;


    int compares = 0;
    int refs = 0;
    int size = 0;

    bool program = true;
    int chosen;
    while (program)
    {
        std::cout
            << "\n_____________________________________";
        std::cout
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 0.Initialize your random array.   |"
            << "\n| 1.Show non-sorted array.          |"
            << "\n| 2.Show sorted array by trade m.   |"
            << "\n| 3.Show sorted array by insert m.  |"
            << "\n| 4.Show sorted array by select m.  |"
            << "\n| 5.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_INIT:
            if (data_set != nullptr)
            {
                mem_clear(data_set);
                data_set = nullptr;
            }
            std::cout << "Enter size of array:";
            std::cin >> size;
            data_set = new Data(size);
            rand_init(data_set);
            break;

        case MENU_SHOW:
            if (data_set != nullptr) show(data_set->_array, size);
            else std::cout << "Initialize array first!\n";

            break;

        case MENU_TRADE:
            if (sorted_ar != nullptr)delete sorted_ar; 
            if (data_set != nullptr)
            {
                sorted_ar = trade_method(data_set->_array, size, compares, refs);
                std::cout << "Count of compares: " << compares << '\n' << "Count of refers:" << refs << '\n';
                show(sorted_ar, size);
            }
            break;

        case MENU_INSERT:
            if (sorted_ar != nullptr) delete sorted_ar;
            if (data_set != nullptr)
            {
                sorted_ar = inserting_m(data_set->_array, size, compares, refs);
                std::cout << "Count of compares: " << compares << '\n' << "Count of refers:" << refs << '\n';
                show(sorted_ar, size);
            }
            break;

        case MENU_SELECT:
            if (sorted_ar != nullptr)  delete sorted_ar;
            if (data_set != nullptr)
            {
                sorted_ar = select_m(data_set->_array, size, compares, refs);
                std::cout << "Count of compares: " << compares << '\n' << "Count of refers:" << refs << '\n';
                show(sorted_ar, size);
            }
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }
    mem_clear(data_set);
    delete sorted_ar;
    return 0;
}

