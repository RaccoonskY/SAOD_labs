#include <iostream>

///LIST OF LISTS///




template<typename T>
struct LNode
{
    T nd_item; //item which contains necessary information ;
    LNode* nd_next; //Pointer on next node;
    LNode* nd_prev;

    LNode(T item, LNode* next, LNode* prev) : nd_item(item), nd_next(next), nd_prev(prev)
    {

    }

};





template<typename T>
struct DList
{
    LNode<T>* m_head;
    DList()
    {
        m_head = new LNode<T>(NULL, m_head, m_head);
        m_head->nd_next = m_head;
        m_head->nd_prev = m_head;
    }
};

template<typename T>
void show(DList<T>& list)
{
    LNode<T>* temp = list.m_head->nd_next;
    while (temp != list.m_head)
    {
        std::cout << temp->nd_item << "---";
        temp = temp->nd_next;
    }
    std::cout << '\n';
}

template<typename T>
void show_rev(DList<T>& list)
{
    LNode<T>* temp = list.m_head->nd_prev;
    while (temp != list.m_head)
    {
        std::cout << temp->nd_item << "---";
        temp = temp->nd_prev;
    }
    std::cout << '\n';

}


template<typename T>
LNode<T>* search(DList<T>& list, const T& searched, const int& mode)
{
    if (mode == 0)
    {
        LNode<T>* temp = list.m_head->nd_next;
        while (temp != list.m_head && temp->nd_item != searched)
        {
            temp = temp->nd_next;
        }
        if (temp == list.m_head)
        {
            return nullptr;
        }
        else
        {

            return temp;
        }
    }
    else if (mode == 1)
    {
        LNode<T>* temp = list.m_head->nd_prev;
        while (temp != list.m_head && temp->nd_item != searched)
        {
            temp = temp->nd_prev;
        }
        if (temp == list.m_head)
        {
            return nullptr;
        }
        else
        {

            return temp;
        }
    }
}


template<typename T>
void search_menu(DList<T>& list, const T& searched, const int& mode)
{
    int position = 0;
    if (mode == 0)
    {
        LNode<T>* temp = list.m_head->nd_next;
        while (temp != list.m_head && temp->nd_item != searched)
        {
            temp = temp->nd_next;
            position++;

        }
        if (temp == list.m_head)
        {
            std::cout << "Element cannot be found! ;( \n";
        }
        else
        {
            std::cout << "Element is found, it's position is " << position << " in right-left direction\n";
        }
    }
    else if (mode == 1)
    {
        LNode<T>* temp = list.m_head->nd_prev;
        while (temp != list.m_head && temp->nd_item != searched)
        {
            temp = temp->nd_prev;
            position++;
        }
        if (temp == list.m_head)
        {
            std::cout << "Element cannot be found! ;( \n";
        }
        else
        {
            std::cout << "Element is found, it's position is " << position << " in left-right direction\n";
        }
    }
}





template<typename T>
void add_elem(DList<T>& list)
{
    T elem;
    T choose;
    int pos_choice = 0;
    int mode = 0;
    LNode<T>* chosen_pos;

    if (list.m_head->nd_next == list.m_head)
    {

        std::cout << "Write your item to add:\n";
        std::cin >> elem;
        LNode<T>* new_item = new LNode<T>(elem, list.m_head, list.m_head);
        list.m_head->nd_next = new_item;
        list.m_head->nd_prev = new_item;

    }
    else
    {

        std::cout << "Write your item to add:\n";
        std::cin >> elem;

        std::cout << " Write mode of searching : 0 - next/ 1 - prev\n";
        do
        {
            std::cout << "Write 0 or 1:  ";
            std::cin >> mode;
            std::cout << '\n';
        } while (mode != 0 && mode != 1);


        show(list);
        do
        {
            std::cout << "Write item where you want to place new item\n";
            std::cin >> choose;

        } while (search(list, choose, mode) == nullptr);


        std::cout << "Do you want to add item before or after chosen?(0/1)\n";
        do
        {
            std::cout << "Write 0 or 1:\n";
            std::cin >> pos_choice;
        } while (pos_choice != 0 && pos_choice != 1);



        if (pos_choice == 1)
        {
            chosen_pos = search(list, choose, mode);
            LNode<T>* next_before = chosen_pos->nd_next;
            LNode<T>* new_item = new LNode<T>(elem, next_before, chosen_pos);
            chosen_pos->nd_next = new_item;
            next_before->nd_prev = new_item;

        }
        else if (pos_choice == 0)
        {
            chosen_pos = search(list, choose, mode);
            LNode<T>* before_pos = chosen_pos->nd_prev;
            LNode<T>* new_item = new LNode<T>(elem, chosen_pos, before_pos);
            before_pos->nd_next = new_item;
            chosen_pos->nd_prev = new_item;

        }
    }
}



template<typename T>
void delete_elem(DList<T>& list)
{
    if (list.m_head->nd_next != list.m_head)
    {
        T choose;
        int mode;
        show(list);

        std::cout << " Write mode of searching of deleted element : 0 - next/ 1 - prev\n";
        do
        {
            std::cout << "Write 0 or 1:  ";
            std::cin >> mode;
            std::cout << '\n';
        } while (mode != 0 && mode != 1);


        do
        {
            std::cout << "Write item what you want to delete\n";
            std::cin >> choose;

        } while (choose != search(list, choose, mode)->nd_item);

        LNode<T>* current_node = search(list, choose, mode);
        LNode<T>* next_node = current_node->nd_next;
        LNode<T>* prev_node = current_node->nd_prev;

        prev_node->nd_next = next_node;
        next_node->nd_prev = prev_node;

        delete current_node;
    }
    else
    {
        std::cout << "Your list is empty!\n";
    }

}

template<typename T>
void mem_clear(DList<T>& list)
{

    LNode<T>* cur = list.m_head->nd_next;
    LNode<T>* next = cur;
    while (cur != list.m_head)
    {
        next = next->nd_next;
        delete cur;
        cur = next;
    }
    delete cur;
}


///////////////////////////////////////////////////////////LIST OF LISTS/////////////////////////////////////////////////////
template<typename T>
struct MainList
{
    MainList* next_main;
    DList<T>* sub_list;
    char l_name = 'o';

    MainList()
    {
        next_main = nullptr;
        sub_list = nullptr;
    }
};



template<typename T>
void show(MainList<T>** m_list)
{
    MainList<T>* pCurMain = (*m_list)->next_main;
    DList<T>* subCur;
    while (pCurMain != nullptr)
    {
        subCur = pCurMain->sub_list;
        std::cout << (pCurMain->l_name)<<":";
        show(*subCur);
        pCurMain = pCurMain->next_main;
    }
}

template<typename T>
void show_subs(MainList<T>& m_list)
{
    MainList<T>* pCurMain = m_list.next_main;
    while (pCurMain != nullptr)
    {
        std::cout << pCurMain->l_name << "---";
        pCurMain = pCurMain->next_main;
    }
    std::cout << '\n';
}



template<typename T>
void search(MainList<T>& m_list, const T& searched)
{
    MainList<T>* pCurMain = m_list.next_main;
    DList<T>* curSub = nullptr;
    while (pCurMain != nullptr)
    {
        curSub = pCurMain->sub_list;
        if (search(curSub, searched, 0) != nullptr)
        {
            std::cout << "Searched element is found at '" << pCurMain->l_name << "' list !\n";
        }
        else
        {
            pCurMain = pCurMain->next_main;
        }
    }
}

template<typename T>
MainList<T>* search_sub(MainList<T>& m_list, const char& searched)
{
    MainList<T>* pCurMain = m_list.next_main;
    while (pCurMain != nullptr)
    {
        if (pCurMain->l_name == searched )
        {
            return pCurMain;
        }
        pCurMain = pCurMain->next_main;
    }
    return nullptr;
}

template<typename T>
MainList<T>* searchprev_sub(MainList<T>& m_list, const char& searched)
{
    MainList<T>* pCurMain = &m_list;
    MainList<T>* pPrev = &m_list;
    while (pCurMain != nullptr)
    {
        pPrev = pCurMain;
        pCurMain = pCurMain->next_main;
        if (pCurMain->l_name == searched)
        {
            return pPrev;
        }
       
    }
    return nullptr;
}

template<typename T>
void add_elem(MainList<T>** m_list)
{
    MainList<T>* pCurMain = (*m_list)->next_main;
    if (pCurMain == nullptr)
    {
        pCurMain = new MainList<T>();
        pCurMain->sub_list = new DList<T>();
        std::cout << "Enter name of new mainlist with char: ";
        std::cin >> pCurMain->l_name;
        add_elem(*(pCurMain->sub_list));
        (*m_list)->next_main = pCurMain;
     
    }
    else
    {   
        char namemain;
        std::cout << "Choose sublist from below:\n";
        show_subs(**m_list);
        std::cin >> namemain;
        
        pCurMain = search_sub(**m_list, namemain);
        add_elem(*(pCurMain->sub_list));
    }

}

template<typename T>
void add_sub(MainList<T>& m_list)
{
    MainList<T>* pCurMain = &m_list;
    while (pCurMain->next_main != nullptr)
    {
        pCurMain = pCurMain->next_main;
    }
    MainList<T>* newLast = pCurMain->next_main;
    newLast = new MainList<T>();
    newLast->sub_list = new DList<T>();
    std::cout << "Enter name of new mainlist with char: ";
    std::cin >> newLast->l_name;
    
    pCurMain->next_main = newLast;
   
}

template<typename T>
void delete_elem(MainList<T>& m_list)
{
    char namemain;
    std::cout << "Choose sublist from below:\n";
    show_subs(m_list);
    std::cin >> namemain;

    MainList<T>* pCurMain = search_sub(m_list, namemain);
    delete_elem(*(pCurMain->sub_list));
}


template<typename T>
void delete_sub(MainList<T>& m_list)
{
    char namemain;
    std::cout << "Choose sublist from below:\n";
    show_subs(m_list);
    std::cin >> namemain;

    MainList<T>* pPrev= searchprev_sub(m_list, namemain);
    MainList<T>* pCur = pPrev->next_main;
    MainList<T>* pNext = pCur->next_main;
    pPrev->next_main = pNext;
    mem_clear(*(pCur->sub_list));
    delete pCur;

}

template<typename T>
void mem_clear(MainList<T>& m_list)
{
    MainList<T>* pFirst = &m_list;
    MainList<T>* pNext;
    while (pFirst != nullptr)
    {
        pNext = pFirst->next_main;
        if (pFirst->sub_list != nullptr)
        {
            mem_clear(*(pFirst->sub_list));
        }
        delete pFirst;
        pFirst = pNext;

       
    }
}

enum Menu {
    MENU_SUB,
    MENU_ADDEL,
    MENU_SHSUBS,
    MENU_SHALL,
    MENU_DLELM,
    MENU_DLSUB,
    MENU_EXIT

};


int main()
{
    MainList<int>* m_list = new MainList<int>();



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
            << "\n| 0.Add new sub list.               |"
            << "\n| 1.Add new elem to sub list.       |"
            << "\n| 2.Show sub lists.                 |"
            << "\n| 3.Show all elements of sub lists. |"
            << "\n| 4.Delete element of sub.          |"
            << "\n| 5.Delete sub list.                |"
            << "\n| 6.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_SUB:
            add_sub(*m_list);
            break;
        case MENU_ADDEL:
            add_elem(&m_list);
            break;
        case MENU_SHSUBS:
            std::cout << "All sublists:\n";
            show_subs(*m_list);
            break;
        case MENU_SHALL:
            std::cout << "All elements of lists:\n";
            show(&m_list);
            break;
        case MENU_DLELM:
            delete_elem(*m_list);
            break;
        case MENU_DLSUB:
            delete_sub(*m_list);
            break;
        case MENU_EXIT:
            program = false;

            std::cout << "\nUnknown command";
            break;
        }

    }










    mem_clear(*m_list);
    return 0;
}
