#include <iostream>

template<typename T>
struct LNode
{
    T nd_item; //item which contains necessary information ;
    LNode* nd_next; //Pointer on next node;

    LNode(T item, LNode* next): nd_item(item), nd_next(next)
    {

    }

};


template<typename T>
struct DList
{
    LNode<T>* m_head;
    DList()
    {
        m_head= new LNode<T>(NULL, nullptr);
    }
};

template<typename T>
void show(DList<T>& list)
{
    LNode<T>* temp = list.m_head->nd_next;
    while (temp != nullptr)
    {
        std::cout << temp->nd_item<<"---";
        temp = temp->nd_next;
    }
    std::cout << '\n';
}

template<typename T>
LNode<T>* search(DList<T>& list, const T& searched)
{
    LNode<T>* temp = list.m_head->nd_next;
    while (temp != nullptr && temp->nd_item != searched)
    {
        temp = temp->nd_next;
    }
    if (temp == nullptr)
    {
        return nullptr;
    }
    else
    {

        return temp;
    }
}

template<typename T>
LNode<T>* search_prev(DList<T>& list, const T& searched)
{
    LNode<T>* temp = list.m_head;
    LNode<T>* temp_prev = temp;
    while (temp != nullptr && temp->nd_item != searched)
    {   
        temp_prev = temp;
        temp = temp->nd_next;
    }

    if (temp == nullptr)
    {
        return nullptr;
    }
    else
    {
        return temp_prev;
    }
}

template<typename T>
void add_elem(DList<T>& list)
{
    T elem;
    T choose;
    int pos_choice;
    LNode<T>* chosen_pos;

    if (list.m_head->nd_next == nullptr)
    {

        std::cout << "Write your item to add:\n";
        std::cin >> elem;
        LNode<T>* new_item = new LNode<T>(elem, nullptr);
        list.m_head->nd_next = new_item;
    }
    else 
    {

        std::cout << "Write your item to add:\n";
        std::cin >> elem;

        show(list);
        do
        {
            std::cout << "Write item where you want to place new item\n";
            std::cin >> choose;

        } while (search(list, choose) == nullptr);


        std::cout << "Do you want to add item before or after chosen?(0/1)\n";
        do
        {
            std::cout << "Write 0 or 1:\n";
            std::cin >> pos_choice;
        } while (pos_choice != 0 && pos_choice != 1);



        if (pos_choice == 1)
        {
            chosen_pos = search(list, choose);
            LNode<T>* next_before = chosen_pos->nd_next;
            LNode<T>* new_item = new LNode<T>(elem, next_before);
            chosen_pos->nd_next = new_item;

        }
        else if(pos_choice == 0)
        {
             chosen_pos = search(list, choose);
             LNode<T>* before_pos = search_prev(list, choose);
             LNode<T>* new_item = new LNode<T>(elem, chosen_pos);
             before_pos->nd_next = new_item;

        }
    }
    


}

template<typename T>
void delete_elem(DList<T>& list, DList<T>& del_list)
{
    if (list.m_head->nd_next != nullptr)
    {
        T choose;
        show(list);
        do
        {
            std::cout << "Write item what you want to delete\n";
            std::cin >> choose;

        } while (choose != search(list, choose)->nd_item);

        LNode<T>* prev_node = search_prev(list, choose);
        LNode<T>* current_node = search(list, choose);

        prev_node->nd_next = current_node->nd_next;

        LNode<T>* temp_del = del_list.m_head;
        LNode<T>* del_prev = temp_del->nd_next;

        temp_del->nd_next = current_node;
        current_node->nd_next = del_prev;
    }
    else
    {
        std::cout << "Your list is empty!\n";
    }


}


template<typename T>
void getback_elem(DList<T>& del_list, DList<T>& list)
{
    if (del_list.m_head->nd_next != nullptr)
    {   
        
        LNode<T>* temp_last = list.m_head;
        while (temp_last->nd_next != nullptr)
        {
            temp_last = temp_last->nd_next;
        }



        LNode<T>* temp_del = del_list.m_head;
        LNode<T>* head_after = temp_del->nd_next;

        temp_del->nd_next = head_after->nd_next;
        head_after->nd_next = nullptr;
        temp_last->nd_next = head_after;

        
        
    }
    else
    {
        std::cout << "Your list of deleted is empty!\n";
    }


}




template<typename T>
void delete_elem(DList<T>& list)
{
    if (list.m_head->nd_next != nullptr)
    {
        T choose;
        show(list);
        do
        {
            std::cout << "Write item what you want to delete\n";
            std::cin >> choose;

        } while (choose != search(list, choose)->nd_item);

        LNode<T>* prev_node = search_prev(list, choose);
        LNode<T>* current_node = search(list, choose);
        LNode<T>* new_cur = current_node->nd_next;

        prev_node->nd_next = new_cur;

        delete current_node;
    }
    else
    {
        std::cout << "Your list is empty!\n";
    }


}


template<typename T> 
void mem_clear(DList<T> list)
{
    LNode<T>* cur = list.m_head;
    LNode<T>* next = cur;
    while (cur != nullptr)
    {
        next = next->nd_next;
        delete cur;
        cur = next;
    }
}


enum Menu {
    MENU_INIT,
    MENU_ADDN,
    MENU_SHST,
    MENU_DEL,
    MENU_SHDEL,
    MENU_EXIT

};


int main()
{
    DList<int> mylist = DList<int>();
    DList<int> del_list = DList<int>();

    bool program = true;
    int chosen;
    int choice;
    while (program)
    {
        std::cout
            << "\n_____________________________________";
        std::cout
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 1.Add new element to your list .  |"
            << "\n| 2.Show current list               |"
            << "\n| 3.Delete one element of list      |"
            << "\n| 4.Show deleted elements.          |"
            << "\n| 5.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {

        case MENU_ADDN:
            std::cout << "Do you want to add new item or last deleted? (0,1)\n";
            do
            {   
                std::cout << "Enter 0 or 1:  ";
                std::cin >> choice;
            } while (choice != 0 && choice != 1 );

            if (choice == 0)
            {
                add_elem(mylist);
            }
            else
            {
                getback_elem(del_list, mylist);
            }
            break;
        case MENU_SHST:
            show(mylist);
            break;
        case MENU_DEL:
            std::cout << "Do you want to delete item or move it to extra stack? (0,1)\n";
            do
            {
                std::cout << "Enter 0 or 1:  ";
                std::cin >> choice;
            } while (choice != 0 && choice != 1);

            if (choice == 0)
            {
                delete_elem(mylist);
            }
            else
            {
                delete_elem(mylist, del_list);
            }
            break;
        case MENU_SHDEL:
            show(del_list);
            break;
        case MENU_EXIT:
            program = false;
            break;
        default:
            std::cout << "\nUnknown command";
            break;
        }

    }


    mem_clear(mylist);
    mem_clear(del_list);
    return 0;
}

