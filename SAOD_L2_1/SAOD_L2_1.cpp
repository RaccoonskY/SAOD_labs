#include <iostream>

        ///                 Тема 3. Задание 2. Статический массив (вариант 1).


struct stList 
{
    int* _list[10];
    int _count = 0;
    int _size = 10;

    stList()
    {
        for (int i = 0; i < _size; i++)
        {
            _list[i] = nullptr;
        }
    }

};


bool list_empty(stList& list)
{
    if (list._count > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool list_full(const stList& list)
{
    if (list._count == list._size)
    {
        return true;
    }
    else
    {
        return false;
    }


}

void show(stList& list)
{

    for (int i = 0; i < list._size ; i++)
    {
        if (list._list[i] == nullptr)
        {
            std::cout << "__" << "---";
        }
        else
        {

            std::cout << *list._list[i] << "---";
        }
        
    }
    std::cout << "\n";
}


int search(const stList& list, const int& seek)
{

    for (int i = 0; i < list._size; i++)
    {
        if (list._list[i] != nullptr)
        {
            if (*list._list[i] == seek)
            {
                std::cout << "Item is found, it's position:" << i << "\n";
                return i;
            }
        }

    }
    std::cout << "Item cannot be found!\n";
    return -1;


}


int search_bigger(const stList& list, const int& seek)
{

    for (int i = 0; i < list._size; i++)
    {
        if (list._list[i] != nullptr)
        {
            if (*list._list[i] > seek)
            {
                std::cout << "Item is found, it's position:" << i << "\n";
                return i;
            }
        }
  
    }
    std::cout << "Item cannot be found!\n";
    return -1;


}

void add_elem(stList& list, const int& item)
{
   
   
    if (list_empty(list))
    {
        list._list[0] = new int(item);
        list._count++;
        std::cout << "NEW STACK:\n";
        show(list);
    }
    else
    {
        if (!list_full(list))
        {   
            int choose = 0;
            int around_id = search_bigger(list, item);
          
            if (around_id == -1)
            {
                list._list[list._count] = new int(item);
                list._count++;
            }
            else
            {
                for (int i = list._count - 1; i > around_id - 1; i--)
                {
                    list._list[i + 1] = list._list[i];
                }
                list._list[around_id] = new int(item);
                list._count++;
            }

            std::cout << "NEW STACK:\n";
            show(list);
        }
        else
        {
            std::cout << "Your list is FULL! \n";
        }

    }
   
}

void del_elem(stList& list)
{
    if (list_empty(list))
    {
        std::cout << "You can't delete with empty list!\n";
    }
    else
    {
        std::cout << "CURRENT STACK:\n";
        show(list);\

        int choose = 0;
        int deleted_id = 0;

        do
        {
            std::cout << "Write the item  which you want to delete\n";
            std::cin >> choose;
            deleted_id = search(list, choose);
        } while (deleted_id == -1);

        delete list._list[deleted_id];
        list._list[deleted_id] = nullptr;

        for (int i = deleted_id; i < list._count-1; i++)
        {
            list._list[i] = list._list[i + 1];
        }
        list._count--;
    }
}


void mem_clear(stList& list)
{
    for (int i = 0; i < list._count - 1; i++)
    {
        if (list._list[i] != nullptr)
        {
            delete list._list[i];
            list._list[i] = nullptr;
        }
  
    }
    list._count = 0;
}



enum Menu {
    MENU_SEARCH,
    MENU_ADDN,
    MENU_SHST,
    MENU_DEL,
    MENU_EXIT

};


int main()
{
    stList myList = stList();


    bool program = true;
    int chosen;
    int deleted_count = 0;

    while (program)
    {
        std::cout
            << "\n_____________________________________";
        std::cout
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 0.Search element in list          |"
            << "\n| 1.Add new element to your list.   |"
            << "\n| 2.Show current list               |"
            << "\n| 3.Delete one element of list      |"
            << "\n| 4.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_SEARCH:
            int search_num;
            std::cout << "Enter a number to search in list !\n";
            std::cin >> search_num;
            search(myList, search_num);
            break;
        case MENU_ADDN:
            int add_num;
            std::cout << "Enter a number to add to list.\n";
            std::cin >> add_num;
            add_elem(myList, add_num);
            break;
        case MENU_SHST:
            std::cout << "Current list is: \n";
            show(myList);
            break;
        case MENU_DEL:
            del_elem(myList);
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }
 mem_clear(myList);
}

