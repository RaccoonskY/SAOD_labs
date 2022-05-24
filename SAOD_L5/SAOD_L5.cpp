#include <iostream>
#include <iomanip>
#include <ctime>


int rand_unit() {

    int randi = 0 + rand() % 100;
    return randi;

}

struct TNode {
    int n_inf, n_key, n_count;
    TNode* n_left;
    TNode* n_right;
   

    TNode()
    {
        n_left = nullptr;
        n_right = nullptr;
        n_count = 1;
    }
};


void backward(TNode*& node, int wsp = 0)
{
    if (node != nullptr)
    {
        backward(node->n_right, wsp + 8);
        std::cout << std::setw(wsp);
        std::cout << node->n_key << ':';
        std::cout << (node->n_inf) << '\n'; //обработка inf  Node (можно использовать для search, условие ставим  ) 
        backward(node->n_left, wsp + 8);

    };
}

void row_output(TNode*& node)
{
    if (node != nullptr)
    {
        row_output(node->n_left);
        std::cout << node->n_key <<'('<<(node->n_count)<<')'<< ':';
        std::cout << (node->n_inf) << ' '; //обработка inf  Node (можно использовать для search, условие ставим  ) 
        row_output(node->n_right);

    };
}


void in_tree(TNode*& pCur)
{
    TNode* pTemp = pCur;
    int searched;
    std::cout << "Enter key of searched elem: ";
    std::cin >> searched;
    bool stop = false;
    while (pTemp != nullptr && !stop)
    {
        if (searched < pTemp->n_key)
        {
            pTemp = pTemp->n_left;
        }
        else
        {
            if (searched > pTemp->n_key)
            {
                pTemp = pTemp->n_right;
            }
            else
            {
                stop = true;
                std::cout << "Item is found!\n";
                std::cout << "It's count is: " << pTemp->n_count<<'\n';
                std::cout << "It's inf part is: " << pTemp->n_inf << '\n';
            }
        }
    }
}

void add_node(TNode*& pCur, const int& key, const int& inf)
{
    if (pCur == nullptr)
    {   
        pCur = new TNode();
        pCur->n_inf = inf;
        pCur->n_key = key;
        pCur->n_left = nullptr;
        pCur->n_right = nullptr;
    }
    else
    {
        if (key < pCur->n_key)
        {
            add_node(pCur->n_left, key, inf);
        }
        else if (key > pCur->n_key)
        {
            add_node(pCur->n_right, key, inf);
        }
        else
        {
            pCur->n_count += 1;
        }
    }
}

void nonrecadd_node(TNode*& root, const int& key, const int& inf)
{
    TNode* pCur = root;
    TNode* pPar = root;
    bool cont = true;
    if (pPar == nullptr)
    {
        pPar = new TNode();
        pPar->n_inf = inf;
        pPar->n_key = key;
        pPar->n_left = nullptr;
        pPar->n_right = nullptr;
        root = pPar;
    }
    else
    {
        while (cont)
        {
            pPar = pCur;
            if (key > pCur->n_key)
            {

                pCur = pCur->n_right;
            }
            else if (key < pCur->n_key)
            {
                pCur = pCur->n_left;
            }

            if (pCur == nullptr)
            {
                cont = false;
                pCur = new TNode();
                pCur->n_inf = inf;
                pCur->n_key = key;
                pCur->n_left = nullptr;
                pCur->n_right = nullptr;

                if (key < pPar->n_key)
                {
                    pPar->n_left = pCur;
                }
                else
                {
                    pPar->n_right = pCur;
                }
            }
            else if (pCur->n_key == key)
            {

                cont = false;
                pCur->n_count += 1;

            }
        }
    }
    
}


void add_menu(TNode*& root)
{
    backward(root);
    int inf, key;
    std::cout << "Enter key part of new node: ";
    std::cin >> key;
    std::cout << "Enter inf part of new node: ";
    std::cin >> inf;
    add_node(root, key, inf);
}


void nonrecadd_menu(TNode*& root)
{

    backward(root);
    int inf, key;
    std::cout << "Enter key part of new node: ";
    std::cin >> key;
    std::cout << "Enter inf part of new node: ";
    std::cin >> inf;
    nonrecadd_node(root, key, inf);

}


void changer(TNode*& pCur, TNode*& changed)
{
    if (pCur->n_right != nullptr)
    {
        changer(pCur->n_right, changed);
    }
    else
    {
        changed->n_inf = pCur->n_inf;
        changed->n_key = pCur->n_key;
        changed = pCur;
        pCur = pCur->n_left;
    }
}




void delete_node(TNode*& pCur, const int& key)
{   
    TNode* pTemp;
    if (pCur == nullptr)
    {
        std::cout << "There is no such node in tree!" << std::endl;
    }
    else
    {
        if (key < pCur->n_key) { delete_node(pCur->n_left, key);}
        else if (key > pCur->n_key) { delete_node(pCur->n_right, key); }
        else
        {
            pTemp = pCur;
            if (pTemp->n_right == nullptr)
            {
                pCur = pTemp->n_left;
            }
            else if (pTemp->n_left == nullptr)
            {
                pCur = pTemp->n_right;
            }
            else
            {
                changer(pCur->n_left, pTemp);
            }
            delete pTemp;
        }
    }

}

void tree_randinit(TNode*& root, const int& n )
{   
    int _n = 0;
    int rand_key, rand_inf;

    while (_n < n)
    {
        rand_key = rand_unit();
        rand_inf = rand_unit();
        add_node(root, rand_key, rand_inf);
        _n++;

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
    MENU_ADDNR,
    MENUT_ROWSHOW,
    MENU_RANDINIT,
    MENU_EXIT

};

int main()
{
    srand(time(0));


    TNode* Root = nullptr;

    bool program = true;
    int chosen, key, n;
    bool search = true;
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
            << "\n| 3.Delete element.                 |"
            << "\n| 4.Add new el. with no rec.        |"
            << "\n| 5.SHOW AS ROW.                    |"
            << "\n| 6.RANDOM INITITALLISATION.        |"
            << "\n| 7.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_SEARCH:
            in_tree(Root);
            break;
        case MENU_ADDN:
            add_menu(Root);
            break;
        case MENU_SHST:
            std::cout << "Current tree:\n";
            backward(Root);
            break;
        case MENU_DEL:
            std::cout << "Enter key to delete element: ";
            std::cin >> key;
            delete_node(Root,key);
            break;
        case MENU_ADDNR:
            nonrecadd_menu(Root);
            break;
        case MENUT_ROWSHOW:
            row_output(Root);
            break;
        case MENU_RANDINIT:
            mem_clear(Root);
            Root = nullptr;
            std::cout << "Enter count of random nodes: ";
            std::cin >> n;
            tree_randinit(Root, n);
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }
    mem_clear(Root);
    return 0;
}
