#include <iostream>
#include <iomanip>
#include <ctime>


int rand_unit() {

    return 0 + rand() % 99;

}

struct TNode {
    int n_inf;
    TNode* n_left;
    TNode* n_right;

    TNode()
    {
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

void search_forward(TNode*& node, const int& searched, TNode*& pTemp, bool& cont)
{
    if (cont)
    {
        if (node != nullptr)
        {
            if (node->n_inf == searched)
            {
                pTemp = node;
                cont = false;
            }
            search_forward(node->n_left, searched, pTemp, cont);
            search_forward(node->n_right, searched, pTemp, cont);

        }
    }


}


void search_backward(TNode*& node, const int& searched, TNode*& pTemp, bool& cont)
{
    if (cont)
    {
        if (node != nullptr)
        {

            search_backward(node->n_left, searched, pTemp, cont);
            search_backward(node->n_right, searched, pTemp, cont);
            if (node->n_inf == searched)
            {
                pTemp = node;
                cont = false;
            }
        }
    }
   

}


void search_symm(TNode*& node, const int& searched, TNode*& pTemp, bool& cont)
{
    if (cont)
    {
        if (node != nullptr)
        {

            search_symm(node->n_left, searched, pTemp, cont);
            if (node->n_inf == searched)
            {
                pTemp = node;
                cont = false;
            }
            search_symm(node->n_right, searched, pTemp, cont);
            
        }
    }


}

void add_tree(TNode*& root)
{
    int added;
    if (root == nullptr)
    {
        root = new TNode();
        std::cout << "Enter an integer to add in the tree:";
        std::cin >> added;
        root->n_inf = added;
    }
    else
    {
        int searched,s_type;
        int right_left = 0;
        TNode* pTemp = nullptr;
        TNode* pNew = nullptr;
        bool search = true;
        symmetric(root);
        std::cout << "Enter searched elem: ";
        std::cin >> searched;

        std::cout << "Enter what type of searching you want:\n 1- forward search\n 2- backward search\n 3-symmetrical search\n";
        std::cin >> s_type;
        if (s_type == 1)
        {
            search_forward(root, searched, pTemp, search);
        }
        if (s_type == 2)
        {
            search_backward(root, searched, pTemp, search);
        }
        else
        {
            search_symm(root, searched, pTemp, search);
        }
        
        if (pTemp->n_left != nullptr && pTemp->n_right != nullptr)
        {
            std::cout << "Impossible to add, all subtrees are occupied!\n";
            
        }
        else
        {
            std::cout << "Enter an integer to add:";
            std::cin >> added;
            pNew = new TNode();
            pNew->n_inf = added;
        if (pTemp->n_left == nullptr && pTemp->n_right == nullptr)
        {   

            std::cout << "Write where to add new tree (1- left, 2- right)\n";
            std::cin >> right_left;
            if (right_left == 1)
            {
                pTemp->n_left = pNew;
            }
            else
            {
                pTemp->n_right = pNew;
            }

        }
        else if (pTemp->n_right == nullptr)
        {
            pTemp->n_right = pNew;
        }
        else if (pTemp->n_left == nullptr)
        {
            pTemp->n_left = pNew;
        }
        }
        

    }


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

enum Menu {
    MENU_ADDN,
    MENU_SEARCH,
    MENU_SHST,
    MENU_DEL,
    MENU_EXIT

};

int main()
{
    //srand(time(0));


    TNode* Root = nullptr;
    TNode* pTemp = nullptr;    
    bool program = true;
    int chosen;
    bool search = true;
    int searched;
    int search_mode;
    while (program)
    {
        std::cout
            << "\n_____________________________________";
        std::cout
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 0.Add new element to your tree.   |"
            << "\n| 1.Search element in tree.         |"
            << "\n| 2.Show current tree.              |"
            << "\n| 3.Clear whole tree.               |"
            << "\n| 4.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_SEARCH:
            pTemp = nullptr;
            search = true;
            std::cout << "Enter integer to search in tree:";
            std::cin >> searched;
            std::cout << "Enter what type of search do you want to do:\n1- forward\n2- backward\n3- symmetric\n";
            std::cin >> search_mode;
            if (search_mode == 1)
            {
                search_forward(Root, searched, pTemp, search);
            }
            if (search_mode == 2)
            {
                search_backward(Root, searched, pTemp, search);
            }
            if (search_mode == 3)
            {
                search_symm(Root, searched, pTemp, search);
            }
            if (pTemp != nullptr)
            {
                std::cout << "Searched item is found!\n";
            }
            else
            {
                std::cout << "There is no such item!\n";
            }
            break;
        case MENU_ADDN:
            add_tree(Root);
            break;
        case MENU_SHST:
            std::cout << "Enter what type of tracking through tree you want:\n1- forward\n2- backward\n3- symmetric\n";
            int mode;
            std::cin >> mode;
            std::cout << "Current tree:\n";
            if (mode == 1)
            {
                forward(Root);
            }
            if (mode == 2)
            {
                backward(Root);
            }
            if (mode == 3)
            {
                symmetric(Root);
            }
            break;
        case MENU_DEL:
            mem_clear(Root);
            Root = nullptr;
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }
    mem_clear(Root);
    return 0;
}
