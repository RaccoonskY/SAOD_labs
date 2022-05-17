#include <iostream>


///                  Тема 3. Задание 3. Линейный список (способ 2). Статика.


template<typename T>
struct stlNode
{
    int _next = NULL;
    T   _item;

};


template<typename T>
struct StList{
    int _size = 10;
    int _count = 0;
    stlNode<T> _list[11];
    
    StList()
    {
      
        for (int i = 1; i <= _size; i++)
        {
            _list[i]._next = -1;
        }
        std::cout << "LIST IS INITIALLIZED!\n";
    }


};

template<typename T>
bool list_is_empty(StList<T>& list)
{
    if (list._list[0]._next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T> 
void show(StList<T>& stlist)
{
    int Cur = stlist._list[0]._next;
    std::cout << "CURRENT LIST :\n";
    while (Cur != NULL)
    {
        std::cout<<stlist._list[Cur]._item<<"---";
        Cur = stlist._list[Cur]._next;
    }
    std::cout << "\n";

}

template<typename T>
int search_before(StList<T>& stlist, const T& target)
{
    int Cur_before=0;
    int Cur = stlist._list[0]._next;
    while (Cur != NULL && stlist._list[Cur]._item != target)
    {   
        Cur_before = Cur;
        Cur = stlist._list[Cur]._next;
    }

    if (Cur == NULL)
    {
        std::cout << "Element cannot be found ! ;( \n";
    }
    else
    {
        return Cur_before;
    }

    return 0;
    
}

template<typename T>
int search(StList<T>& stlist, const T& target)
{

    int Cur = stlist._list[0]._next;
    while (Cur != NULL && stlist._list[Cur]._item != target)
    {
        Cur = stlist._list[Cur]._next;
    }

    if (Cur == NULL)
    {
        std::cout << "Element cannot be found ! ;( \n";
    }
    else
    {
        return Cur;
    }

    return 0;

}


template<typename T>
int menu_search(StList<T>& stlist, const T& target)
{
    int pos_count = 0;
    int Cur = stlist._list[0]._next;
    while (Cur != NULL && stlist._list[Cur]._item != target)
    {
        Cur = stlist._list[Cur]._next;
        pos_count++;
    }

    if (Cur == NULL)
    {
        std::cout << "Element cannot be found ! ;( \n";
    }
    else
    {
        std::cout << "Position at massive: " << Cur << "\n" << "Position at list: " << pos_count << '\n';
     
    }

    return 0;

}

template<typename T>
void add_elem(StList<T>& stList)
{
    T elem;
    T choose;
    int pos_choice;
    int new_i_pos = 0;
    int chosen_pos;
    int i = 1;

    if (stList._count == 0 )
    {   
        
        std::cout << "Write your item to add:\n";
        std::cin >> elem;
        chosen_pos = 0;
        while (new_i_pos == 0)
        {
            if (stList._list[i]._next == -1)
            {
                new_i_pos = i;
            }
            i++;
        }
        stList._list[chosen_pos]._next = new_i_pos;
        stList._list[new_i_pos]._next = NULL;
        stList._list[new_i_pos]._item = elem;
        stList._count++;
    }
    else if (stList._count != stList._size)
    {   
        
        std::cout << "Write your item to add:\n";
        std::cin >> elem;
        
        show(stList);
        do
        {
            std::cout << "Write item where you want to place new item\n";
            std::cin >> choose;
        } while (choose != stList._list[search(stList,choose)]._item);

        
        std::cout << "Do you want to add item before or after chosen?(0/1)\n";
        do
        {
            std::cout << "Write 0 or 1:\n";
            std::cin >> pos_choice;
        } while (pos_choice != 0 && pos_choice != 1);


       
        if (pos_choice == 1)
        {
            chosen_pos = search(stList, choose);
            while (new_i_pos == 0)
            {
                if (stList._list[i]._next == -1)
                {
                    new_i_pos = i;
                }
                i++;
            }
            int prev_next = stList._list[chosen_pos]._next;
            stList._list[chosen_pos]._next = new_i_pos;
            stList._list[new_i_pos]._next = prev_next;
            stList._list[new_i_pos]._item = elem;

        }
        else
        {
            int pos_before = search_before(stList, choose);
            chosen_pos = search(stList, choose);
            while (new_i_pos == 0)
            {
                if (stList._list[i]._next == -1)
                {
                    new_i_pos = i;
                }
                i++;
            }
            stList._list[pos_before]._next = new_i_pos;
            stList._list[new_i_pos]._next = chosen_pos;
            stList._list[new_i_pos]._item = elem;

        }
        stList._count++;
    }
    else
    {
        std::cout << "Your list is FULL! \n";
    }
}

template<typename T>
void del_item(StList<T>& mylist)
{
    if (!list_is_empty(mylist))
    {
        T choose;
        show(mylist);
        do
        {
            std::cout << "Write item what you want to delete\n";
            std::cin >> choose;
        
        } while (choose != mylist._list[search(mylist, choose)]._item);

        int id_before = search_before(mylist, choose);
        int id_current = search(mylist, choose);
        int id_next = mylist._list[id_current]._next;

        mylist._list[id_current]._next = -1;
        mylist._list[id_before]._next = id_next;
        mylist._count--;
    }
    else
    {
        std::cout << "List is empty!\n";
    }

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
    StList<int> myList = StList<int>();


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
            menu_search(myList, search_num);
            break;
        case MENU_ADDN:
            add_elem(myList);
            break;
        case MENU_SHST:
            std::cout << "Current list is: \n";
            show(myList);
            break;
        case MENU_DEL:
            del_item(myList);
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }
}



