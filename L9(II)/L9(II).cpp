#include <iostream>
#include <ctime>
#include "data_sets.h"
#include "simple_pocket.h"
#include "repeat_pocket.h"
#include "grading_sort.h"


int rand_int(const int& _highest) {

    int randi = 0 + rand() % _highest;
    return randi;

}

void rand_init(Data*& data, const int& size )
{
    for (int i = 0; i < data->_size; i++)
    {
        data->_array[i].inf = rand_int(size);
        data->_array[i].key = rand_int(size);
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
        mass[i].inf = rand_int(size - 1);
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

int grade_of_size(const int& size)
{
    int temps = size;
    int grade = 1;
    while (temps > 10)
    {
        temps /= 10;
        grade++;
    }
    return grade;
}

void mem_clear(Data*& data)
{
    delete data->_array;
    delete data;
}

void null_init(ListNode* list[], const int& size)
{
    for (size_t i = 0; i < size; i++)
    {
        list[i] = nullptr;
    }
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
    ListNode** lists = nullptr;
   
   
    int compares = 0;
    int refs = 0;
    int size = 0;
    int k, max_by_grade;

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
            data_set = new Data(size);

            std::cout << "Enter the maximum grade of random numbers: ";
            std::cin >> k;
            max_by_grade = pow(10, k);
            std::cout << "\nMaximum possible: " << max_by_grade;

            if (init_mode == 0)
            {
                unique_init(data_set, size);
            }
            else
            {
                rand_init(data_set, max_by_grade);
                lists = new ListNode*  [max_by_grade];
                null_init(lists, max_by_grade);

            }   
            break;
        case MENU_GRADE:
            if (sorted_ar != nullptr)  delete[] sorted_ar;
            sorted_ar = grading_sort(data_set->_array, size,k, compares, refs);
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
                        compares = 0; refs = 0;
                        sorted_ar = simple_pocket(data_set, size, compares, refs);
                    }
                    else
                    {
                        compares = 0; refs = 0;
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
            if (init_mode == 1)
            {
                mem_clear(lists, max_by_grade);
                repeat_pocket(data_set->_array, lists, size, compares, refs);
                std::cout << "\nCount of compares: " << compares << '\n' << "Count of refers:" << refs << '\n';
                show(lists, size);
            }
            else
            {
                std::cout << "You can't use repeating pocket method with unique elements array! \n";
            }
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

    if (data_set != nullptr)
    {
        mem_clear(data_set);
    }
    if (lists != nullptr)
    {
        mem_clear(lists, max_by_grade);
    }
    
    delete[] sorted_ar;
    return 0;
}

