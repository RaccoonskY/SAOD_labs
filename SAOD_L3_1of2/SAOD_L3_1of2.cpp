#include <iostream>

									///LINEAR BI-DIRECTIONAL DYNAMIC LIST///

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
LNode<T>* search(DList<T>& list,const T& searched, const int& mode)
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
    int mode = 0 ;
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

        } while (choose != search(list, choose,mode)->nd_item);

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



enum Menu {
    MENU_SEARCH,
    MENU_ADDN,
    MENU_SHST,
    MENU_DEL,
    MENU_EXIT

};


int main()
{
    DList<int> myList = DList<int>();


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
            int search_mode;
            std::cout << "Enter a number to search in list !\n";
            std::cin >> search_num;
            std::cout << "Enter a mode of searching (0 - direct, 1 - reversed)\n";
            std::cin >> search_mode;
            search_menu(myList, search_num, search_mode);
            break;
        case MENU_ADDN:
            add_elem(myList);
            break;
        case MENU_SHST:
            std::cout << "Show mass in right or left direction:(0,1)\n";
            int mode;
            std::cin >> mode;
            std::cout << "Current list:\n";
            if (mode == 0)
            {
                show(myList);
            }
            else if(mode == 1)
            {
                show_rev(myList);
            }

            break;
        case MENU_DEL:
            delete_elem(myList);
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }
    mem_clear(myList);
}
