#include <iostream>
#include <iomanip>
#include <ctime>

///AVL TREE


int rand_unit() {

    int randi = 0 + rand() % 10;
    return randi;

}

struct TNode {
    int _inf;
    TNode* _nParent;
    TNode* _nChild;


    TNode(const int inf) : _inf(inf)
    {
        _nParent = nullptr;
        _nChild = nullptr;
    }
};



void show(TNode*& root)
{
    TNode* pcParent = root;
    TNode* pcChild;
    while (pcParent != nullptr)
    {
        std::cout << pcParent->_inf<<": ";
        pcChild = pcParent->_nChild;
        while (pcChild != nullptr)
        {
            std::cout << pcChild->_inf<<"---";
            pcChild = pcChild->_nChild;
        }
        std::cout <<"\n|\n";
        pcParent = pcParent->_nParent;
    }

}

TNode* par_search(TNode*& root, const int& searched)
{
    TNode* pTemp = root;
    while (pTemp != nullptr)
    {
        if (pTemp->_inf == searched)
        {
            return pTemp;
        }
        pTemp = pTemp->_nParent;
    }
    return nullptr;
}

TNode* child_search(TNode*& root, const int& searched)
{
    TNode* pTemp = root;
    TNode* pChild;
    while (pTemp != nullptr)
    {   
        pChild = pTemp->_nChild;
        while (pChild!= nullptr)
        {
            if (pChild->_inf == searched)
            {
                return pTemp;
            }
            pChild = pChild->_nChild;
        }
        pTemp = pTemp->_nParent;
    }
    return nullptr;
}

void add_parent(TNode*& root, const int& inf)
{
    TNode* pBefore = root;
    TNode* pTemp = root->_nParent;
    while (pTemp!=nullptr)
    {   
        pBefore = pTemp;
        pTemp = pTemp->_nParent;
    }
    pTemp = new TNode(inf);
    pBefore->_nParent = pTemp;

}

void add_node(TNode*& root, const int& parent_inf, const int& new_item)
{
    TNode* ptParent = par_search(root, parent_inf);
    TNode* ptChild;
    TNode* ptBefore;
    if (ptParent != nullptr)
    {
        ptBefore = ptParent;
        ptChild = ptParent->_nChild;
        while (ptChild != nullptr)
        {   
            ptBefore = ptChild;
            ptChild = ptChild->_nChild;
        }
        ptChild = new TNode(new_item);
        ptBefore->_nChild = ptChild;

    }
    else
    {
        ptParent = child_search(root, parent_inf);
        if (ptParent != nullptr)
        {
            add_parent(root, parent_inf);
            ptParent = par_search(root, parent_inf);
            ptChild = new TNode(new_item);
            ptParent->_nChild = ptChild;
        }
    }
}

TNode* par_for_par(TNode*& root, const int& searched)
{
    TNode* pTemp = root;
    TNode* pBefore = root;
    while (pTemp != nullptr)
    {   
        
        if (pTemp->_inf == searched)
        {
            return pBefore;
        }
        pBefore = pTemp;
        pTemp = pTemp->_nParent;
    }
    return nullptr;

}


TNode* find_child(TNode*& root, const int& searched)
{
    TNode* pTemp = root;
    TNode* pChild;
    while (pTemp != nullptr)
    {
        pChild = pTemp->_nChild;
        while (pChild != nullptr)
        {
            if (pChild->_inf == searched)
            {
                return pChild;
            }
            pChild = pChild->_nChild;
        }
        pTemp = pTemp->_nParent;
    }
    return nullptr;
}

void delete_node(TNode*& root, const int& del_inf)
{
    TNode* pPar;
    TNode* pTemp;
    TNode* delPt = par_search(root, del_inf);
    
    if (delPt != nullptr)
    {
        pPar = child_search(root, del_inf);
        delPt = find_child(root, del_inf);
        pTemp = pPar;
        while ((pTemp->_nChild) != delPt)
        {
            pTemp = pTemp->_nChild;

        }
        pTemp->_nChild = (delPt->_nChild);
        delete delPt;

        delPt = par_search(root, del_inf);
        pTemp = pPar;
        while ((pTemp->_nChild) != nullptr)
        {
            pTemp = pTemp->_nChild;

        }
        pTemp->_nChild = (delPt->_nChild);
        pPar = par_for_par(root, del_inf);
        pPar->_nParent = (delPt->_nParent);
        delete delPt;
    }
    else 
    {
        delPt = find_child(root, del_inf);
        if (delPt != nullptr)
        {
            TNode* pPar = child_search(root, del_inf);
            pTemp = pPar;
            while ((pTemp->_nChild) != delPt)
            {
                pTemp = pTemp->_nChild;

            }
            pTemp->_nChild = (delPt->_nChild);
            delete delPt;

            if (pPar->_nChild == nullptr)
            {
                pTemp = par_for_par(root, pPar->_inf);
                pTemp->_nParent = (pPar->_nParent);
                delete pPar;
            }
        }

    }
}


void menu_search(TNode*& root)
{
    int searched;
    std::cout << "Enter inf of searched item:";
    std::cin >> searched;
    if (par_search(root, searched) != nullptr || find_child(root,searched) != nullptr)
    {
        std::cout << "Item is FOUND!\n";
    }
    else
    {
        std::cout << "Item is NOT FOUND!\n";
    }
}

void menu_add(TNode*& root)
{   
    show(root);
    int new_item, parent_item;
    std::cout << "Enter parent inf : ";
    std::cin >> parent_item;
    std::cout << "Enter inf of new item: ";
    std::cin >> new_item;

    add_node(root, parent_item, new_item);

}



void menu_del(TNode*& root)
{
    show(root);
    int del_item;
    std::cout << "Enter inf of deleted item: ";
    std::cin >> del_item;

    delete_node(root, del_item);

}


void mem_clear(TNode*& root)
{
    TNode* pParent = root;
    TNode* pChild;
    TNode* pNextChild;
    TNode* pNextParent;
    while (pParent!= nullptr)
    {
        pChild = pParent->_nChild;
        pNextChild = pChild->_nChild;
        pNextParent = pParent->_nParent;
        while (pChild!= nullptr)
        {
            delete pChild;
            pChild = pNextChild;
            pNextChild != nullptr ? pNextChild = pNextChild->_nChild: nullptr;
        }
        delete pParent;
        pParent = pNextParent;
        pNextParent != nullptr ? pNextParent = pNextParent->_nChild : nullptr;
    }
    std::cout << "The tree is cleared.\n";

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
    TNode* Root = new TNode(0);

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
            << "\n| 0.Add new element to your tree.   |"
            << "\n| 1.Search element in tree.         |"
            << "\n| 2.Show current tree.              |"
            << "\n| 3.Delete element.                 |"
            << "\n| 4.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_SEARCH:
            menu_search(Root);
            break;
        case MENU_ADDN:
            menu_add(Root);
            break;
        case MENU_SHST:
            std::cout << "Current tree:\n";
            show(Root);
            break;
        case MENU_DEL:
            menu_del(Root);
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }
    mem_clear(Root);
    return 0;
}