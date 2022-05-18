#include <iostream>
#include <iomanip>
#include <ctime>
                                ///TREE 1 of 3 ///



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
        std::cout<<(node->n_inf)<<'\n'; //обработка inf  Node (можно использовать для search, условие ставим  ) 
        forward(node->n_left, wsp+5);
        forward(node->n_right, wsp+5);
    };

}


void symmetry(TNode*& root){
    TNode* pCur = root;
    while (pCur->n_left != nullptr )
    {
        ///заносим в СТЕК все вершины pcur.left
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
        delete node;
        mem_clear(pTempL);
        mem_clear(pTempR);
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



    mem_clear(Root);
    return 0;
}
