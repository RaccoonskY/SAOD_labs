#include <iostream>
#include <ctime>
#include "data_sets.h"
#include "simple_pocket.h"
#include "repeat_pocket.h"
#include "grading_sort.h"


int rand_int() {

    int randi = 0 + rand() % 100;
    return randi;

}

void rand_init(Data*& data)
{
    for (int i = 0; i < data->_size; i++)
    {
        data->_array[i].inf = rand_int();
        data->_array[i].key = rand_int();
    }
}

void unique_init(Data*& data, const int& size)
{
    int cur_rand;
    Item* mass = data->_array;
    int* temp_mas = new int[size];

    for (int i = 0; i < size; i++)
    {
        cur_rand = 0 + rand() % size;
        while (temp_mas[cur_rand] == -1)
        {
            cur_rand = 0 + rand() % size;
        }
        temp_mas[cur_rand] = -1;
        mass[i].key = cur_rand;
        mass[i].inf = rand_int();
    }
    delete[] temp_mas;
}


void show(Data* data, int size)
{   
    Item* arr = data->_array;
    for (int i = 0; i < size; i++)
    {
        std::cout << ' ' << arr[i].key<<'('<<arr[i].inf<<')';
    }
}

void show(Item* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << ' ' << data[i].key << '(' << data[i].inf << ')';
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
    MENU_POCKET,
    MENU_REPEAT,
    MENU_GRADE,
    MENU_EXIT

};

int main()
{
    srand(time(0));

    Data* data_set = nullptr;
    Item* sorted_ar = nullptr;
    ListNode* lists[100];

    for (int i = 0; i < 100; i++)
    {
        lists[i] = nullptr;
    }

    int compares = 0;
    int refs = 0;
    int size = 0;

    bool program = true;
    int chosen, mode, init_mode;
    while (program)
    {
        std::cout
            << "\n_____________________________________";
        std::cout
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 0.Initialize your rand array.     |"
            << "\n| 1.Show non-sorted array.          |"
            << "\n| 2.Show sorted array by pocket m.  |"
            << "\n| 3.Show sorted repeating ar. by p.m|"
            << "\n| 4.Show sorted grading ar. by p.m  |"
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
            std::cout << "Unique elements? (0 - yes, 1 - no)";
            std::cin >> init_mode;
            while (init_mode != 0 && init_mode != 1)
            {
                std::cout << "Invalid choose, try again: ";
                std::cin >> init_mode;
            }

            std::cout << "Enter size of array:";
            std::cin >> size;
            while (init_mode == 1 && size < 100)
            {
                std::cout << "Amount of ununique elements must be > 100!";
                std::cin >> size;
            }
          
            data_set = new Data(size);

            if (init_mode == 0)
            {
                unique_init(data_set, size);
            }
            else
            {
                rand_init(data_set);
            }   
            break;
        case MENU_GRADE:
            if (sorted_ar != nullptr)  delete[] sorted_ar;
            sorted_ar = grading_sort(data_set->_array, size, compares, refs);
            std::cout << "\nCount of compares: " << compares << '\n' << "Count of refers:" << refs << '\n';
            show(sorted_ar, size);
            break;
        case MENU_POCKET:
            if (init_mode == 0)
            {
                if (sorted_ar != nullptr)  delete[] sorted_ar;
                if (data_set != nullptr)
                {
                    std::cout << "Enter of mode of simple-pocket method: 0 - with array, 1 - without: ";
                    std::cin >> mode;
                    while (mode != 0 && mode != 1)
                    {
                        std::cout << "Invalid choose, try again: ";
                        std::cin >> mode;
                    }
                    if (mode == 0)
                    {
                        sorted_ar = simple_pocket(data_set, size, compares, refs);
                    }
                    else
                    {
                        sorted_ar = simple_pocket2(data_set, size, compares, refs);
                    }
                    std::cout << "\nCount of compares: " << compares << '\n' << "Count of refers:" << refs << '\n';
                    show(sorted_ar, size);
                }
            }
            else
            {
                std::cout << "Your elements are not unique, use other way of sorting!\n";
            }
            break;
        case MENU_REPEAT:
            mem_clear(lists);
            repeat_pocket(data_set->_array, lists, size, compares, refs);
            std::cout << "\nCount of compares: " << compares << '\n' << "Count of refers:" << refs << '\n';
            show(lists);
            break;
        case MENU_SHOW:
            if (data_set != nullptr) show(data_set->_array, size);
            else std::cout << "Initialize array first!\n";
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }

    mem_clear(data_set);
    mem_clear(lists);
    delete[] sorted_ar;
    return 0;
}

