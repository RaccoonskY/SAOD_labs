#include <iostream>
#include <cstdlib>
#include <ctime>

                                                       /*#1 LAB TASK (1-4) SECTION 1-2 -----------DONE*/




/// <summary>
/// Node of struct "Stack" which includes item of template type and pointer on next node; 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
struct SNode
{
    T nd_item; //item which contains necessary information ;
    SNode* nd_next; //Pointer on next node;

};


/// <summary>
/// Function for addding new item to stack, it creates new node with dynamic memory and gives it ptr on next node;
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="last"></param>
/// <param name="item"></param>
template<typename T>
void push(SNode<T>** last, const T& item)
{
    SNode<T>* new_last = new SNode<T>{ item, *last}; // initialization of new node with arguments: 
                                                     // 1)contained information, 2)pointer on last added node;
   *last = new_last;  //giving our main pointer (of last added obj) new made ptr;

};





/// <summary>
/// Function, that returns 'true' if it's nullptr or next node is nullptr  
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="current"></param>
/// <returns></returns>
template<typename T>
bool empty_st(SNode<T>* current) { 
    if (current == nullptr )
    {
        return true;
    }
    else
    {
        return false;
    }

};



/// <summary>
/// Function allowing us to delete last added item (node)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="last"></param>
template<typename T>
void pop_st(SNode<T>** last) {
    if (!empty_st(*last))
    {
        (*last)->nd_item = NULL;
        SNode<T>* temp = (*last)->nd_next;
        delete* last;
        *last = temp;
    }
};

template<typename T>
void pop_and_add(SNode<T>** last, SNode<T>** deleted_node) {
    if (!empty_st(*last))
    {

        SNode<T>* temp = *last;
        *last = (*last)->nd_next;
        SNode<T>* temp_del = *deleted_node;
        (*deleted_node) = temp;
        (*deleted_node)->nd_next = temp_del;


    }
};



/// <summary>
/// Funct. showing or data from the last added to first; 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="last"></param>
template<typename T>
void show(SNode<T>* last) {
    SNode<T>* temp_last;
    temp_last = last;
    bool cont = true;

    while (cont)
    {
        if (temp_last == nullptr)
        {
            cont = false;
        }
        else
        {
            std::cout << temp_last->nd_item << "---";
            temp_last = temp_last->nd_next;
        }
        
    }
}



/// <summary>
/// Funct. returning random int 0 - 10; 
/// </summary>
/// <param name="a"></param>
/// <returns></returns>
int rand_unit(int a) {
   
    return 0.0 + rand() % 100;

}



/// <summary>
/// initiallizing ur stack with 'how_many' elements;
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="stack"></param>
/// <param name="how_many"></param>
template<typename T>
void init_Stack(SNode<T>** stack, int how_many) {

    for (size_t i = 0; i < how_many; i++)
    {
        int randf = rand_unit(1);
        std::cout << "new rand was made  = " << randf << "\n";
        push(&*stack, randf);
    }


}



template<typename T>
void mem_clear(SNode<T>** stack)
{
    while ((*stack)->nd_next != nullptr && (*stack != nullptr))
    {
        std::cout << "\nDeleting : " << (*stack)->nd_item ;
        pop_st(stack);
        
    }
    if ((*stack)->nd_next == nullptr)
    {
        std::cout << "\nDeleting : " << (*stack)->nd_item;
        pop_st(stack);
        delete* stack;
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
    srand(time(0));

    //initialization of first stack's node 
    SNode<int>* stack = new SNode<int>{ 0, nullptr };
    //initialization of stack for deleted elements
    SNode<int>* del_stack = nullptr; 


    bool program = true;
    int stage = 0;//stage = 0 - stack is not initiallized, stage = 1 - stack is made
    int chosen;
    int deleted_count = 0;

    while (program) 
    {
        std::cout 
            <<"\n_____________________________________";
        std::cout 
            <<"\n| Choose what you want from menu:   |";
        std::cout
            <<"\n|___________________________________|";
        std::cout 
            <<"\n| 0.Initialization of stack         |"
            <<"\n| 1.Add new element to your stack.  |"
            <<"\n| 2.Show current stack              |"
            <<"\n| 3.Delete one element of stack     |"
            <<"\n| 4.Show deleted elements.          |"
            <<"\n| 5.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_INIT:
            if (stage == 0)
            {
                
                int choice = 1337;
                std::cout << "INITIALIZATION STARTED" << std::endl;
                std::cout << "Do you want random initialization or fixed (0,1) ?\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                while ((choice != 0 ) && (choice != 1))
                {
                    std::cout << "\nEnter your choice: ";
                    std::cin >> choice;
                }
                if (choice == 0)
                {   
                    stack->nd_item = rand_unit(1);
                    stack->nd_next = nullptr;
                    init_Stack(&stack, rand_unit(1));
                }
                else
                {
                    int entered_num;
                    std::cout << "\nEnter number of first number : ";
                    std::cin >> entered_num;
                    stack->nd_item = entered_num;
                    stack->nd_next = nullptr;
                }
                stage = 1;
            }
            else
            {
                std::cout << "\n Stack is already initialized, please clear data to reinitiallizing !";
            }
            break;


        case MENU_ADDN:
            if (stage == 1)
            {
                int _choice = 0;
                std::cout << "\nDo you want to add NEW number or last deleted? (0,1) ?" << std::endl;
                std::cin >> _choice;
                while ((_choice != 0) && (_choice != 1))
                {
                    std::cout << "\nEnter your choice: ";
                    std::cin >> _choice;
                }
                if (_choice == 0)
                {
                    int num_add;
                    std::cout << "\nEnter a number to add: ";
                    std::cin >> num_add;
                    push(&stack, num_add);
                }
                else
                {
                    if (deleted_count != 0 && del_stack!= nullptr)
                    {
                        pop_and_add(&del_stack, &stack);
                    }

                }
            }
            else
            {
                std::cout << "\nPlease, initialize stack first !";
            }
            break;

        case MENU_SHST:
            if (stage == 1)
            {
                show(stack);
            }
            else
            {
                std::cout << "\nPlease, initialize stack first !";
            }
            break;


        case MENU_DEL:
            if (stage == 1)
            {
                int _choicedel;
                std::cout << "\nDo you want to pop item or pop with adding to del stack?(0,1) " << std::endl;
                std::cin >> _choicedel;
                while ((_choicedel != 0) && (_choicedel != 1))
                {
                    std::cout << "\nEnter your choice 1 or 0 please: ";
                    std::cin >> _choicedel;
                }
                if (_choicedel == 0)
                {
                    pop_st(&stack);
                }
                else
                {
                    pop_and_add(&stack, &del_stack);
                }
            }
            else
            {
                std::cout << "\nPlease, initialize stack first !";
            }

            deleted_count++;
            break;



        case MENU_SHDEL:
            if (stage == 1)
            {
                show(del_stack);
            }
            else
            {
                std::cout << "\nPlease, initialize stack first !";
            }
            break;


        case MENU_EXIT:
            std::cout << "EXIT!";
            program = false;
            break;


        default:
            std::cout << "\nUnknown command";
            break;
        }


    }
   
    


    mem_clear(&stack);
    mem_clear(&del_stack);
}

