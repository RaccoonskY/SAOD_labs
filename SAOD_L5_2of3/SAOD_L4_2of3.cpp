#include <iostream>
#include <iomanip>
#include <ctime>
///TREE 1 of 3 ///



/// <summary>
/// Node of struct "Stack" which includes item of template type and pointer on next node; 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
struct SNode
{
    T nd_item; //item which contains necessary information ;
    SNode* nd_next; //Pointer on next node
    int st_wsp=-1;

    
  
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
    SNode<T>* new_last = new SNode<T>{ item, *last }; // initialization of new node with arguments: 
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
    if (current == nullptr)
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
        std::cout << "\nDeleting : " << (*stack)->nd_item;
        pop_st(stack);

    }
    if ((*stack)->nd_next == nullptr)
    {
        std::cout << "\nDeleting : " << (*stack)->nd_item;
        pop_st(stack);
        delete* stack;
    }


}


int rand_unit() {

    return 0 + rand() % 99;

}

struct TNode {
    int n_inf;
    TNode* n_left;
    TNode* n_right;

    TNode()
    {
        n_inf = rand_unit();
        n_left = nullptr;
        n_right = nullptr;
    }
};



void init(TNode*& root, int size)
{
    int Nl, Nr;
    TNode* pTemp;
    if (size == 0)
    {
        root = nullptr;
    }
    else
    {
        Nl = size / 2;
        Nr = size - Nl - 1;
        pTemp = new TNode();
        init(pTemp->n_left, Nl);
        init(pTemp->n_right, Nr);
        root = pTemp;

    }

}



void forward(TNode*& node, int wsp = 0)
{

    if (node != nullptr)
    {
        std::cout << std::setw(wsp);
        std::cout << (node->n_inf) << '\n'; //обработка inf  Node (можно использовать для search, условие ставим  ) 
        forward(node->n_left, wsp + 5);
        forward(node->n_right, wsp + 5);
    };

}


void nonrec_symmetric(TNode*& root) {
    TNode* pCur = root->n_left;
    bool stop = false;
    SNode<TNode*>* stack = new SNode<TNode*>{ root, nullptr };
    stack->st_wsp += 1;
    int wsp = 5;
    int st_size = 0;
    while (!stop)
    {   

        while (pCur != nullptr)
        {
            push(&stack, pCur);
            st_size++;
            stack->st_wsp  = st_size;

            pCur = pCur->n_left;
          
        }
        if (empty_st(stack))
        {
            stop = true;
        }
        else
        {            
            pCur = stack->nd_item;
            std::cout << std::setw(wsp * (stack->st_wsp));
            std::cout << (pCur->n_inf) << '\n';
            st_size = stack->st_wsp;
            pCur = pCur->n_right;
            pop_st(&stack);

        }

    }
    
}

void symmetric(TNode*& node, int wsp = 0)
{
    if (node != nullptr)
    {
        symmetric(node->n_left, wsp + 5);
        std::cout << std::setw(wsp);
        std::cout << (node->n_inf) << '\n'; //обработка inf  Node (можно использовать для search, условие ставим  ) 
        symmetric(node->n_right, wsp + 5);
    };
}


void backward(TNode*& node, int wsp = 0)
{
    if (node != nullptr)
    {
       
        backward(node->n_right, wsp + 5);
        std::cout << std::setw(wsp);
        std::cout << (node->n_inf) << '\n'; //обработка inf  Node (можно использовать для search, условие ставим  ) 
        backward(node->n_left, wsp + 5);

    };
}

TNode* search_forward(TNode*& node, int searched)
{
    if (node != nullptr)
    {
        if (node->n_inf == searched)
        {
            return node;
        }
        search_forward(node->n_left, searched);
        search_forward(node->n_right, searched);
    };
}

void mem_clear(TNode*& node)
{
    if (node != nullptr)
    {

        TNode* pTempL = node->n_left;
        TNode* pTempR = node->n_right;
        mem_clear(pTempL);
        mem_clear(pTempR);
        delete node;

    }
}


int main()
{
    srand(time(0));


    TNode* Root;
    int size;
    std::cout << "Enter amount of vetices of the tree: ";
    std::cin >> size;
    init(Root, size);
    std::cout << "FORWARD:\n\n";
    forward(Root);
    std::cout << "-------------------------\n";
    std::cout << "BACKWARD:\n\n";
    backward(Root);
    std::cout << "-------------------------\n";
    std::cout << "SYMMETRIC:\n\n";
    symmetric(Root);
    std::cout << "-------------------------\n";
    std::cout << "NON RECURSION SYMMETRIC:\n\n";
    nonrec_symmetric(Root);



    mem_clear(Root);
    return 0;
}
