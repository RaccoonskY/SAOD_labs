#include <iostream>
#include <ctime>
#include <string>

struct ListItem {
    std::string _name;
    ListItem* _next;

    ListItem(std::string name): _name(name)
    {
        _next = nullptr;
    }
};

struct HashItem {
    ListItem* _first = nullptr;
    ListItem* _last = nullptr;
};


int hashf_key(std::string str, const int& m)
{
    int hash_key = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        hash_key += (int)str[i];
    }
    hash_key = hash_key % m;
    return hash_key;
}

bool is_in_table(std::string searched, HashItem h_table[], const int& size)
{
    int hash_key = hashf_key(searched, size);
    ListItem* temp = h_table[hash_key]._first;

    while (temp->_name != searched)
    {
        temp = temp->_next;
        if (temp == nullptr)
        {
            return false;
        }
    }
    return true;


}

void hash_func(std::string str, HashItem hash_table[], const int& m, int& compares, int& refers)
{

    int hash_key = hashf_key(str, m);
    ListItem* temp = hash_table[hash_key]._first;

    if (temp == nullptr)
    {
        compares++;
        hash_table[hash_key]._first = new ListItem(str);
        hash_table[hash_key]._last = hash_table[hash_key]._first;
    }
    else
    {
        if (is_in_table(str, hash_table,m))
        {
            std::cout << "\nThere is already such element in hash table!\n";
            return;
        }

        hash_table[hash_key]._last->_next = new ListItem(str);
        hash_table[hash_key]._last = hash_table[hash_key]._last->_next;

    }
    std::cout << "Succefully added on position: " << hash_key << '\n';
    refers++;
    
};


void show(HashItem h_table[], const int& size)
{
    ListItem* temp;
    for (int i = 0; i < size; i++)
    {
         temp = h_table[i]._first;
         std::cout << "I(" << i << "): ";
         while (temp!=nullptr)
         {
             std::cout << temp->_name<<" --> ";
             temp = temp->_next;
         }
         std::cout << std::endl;

    }
}

void search(std::string searched, HashItem h_table[], const int& size, int& compares, int& refers)
{
    int hash_key = hashf_key(searched, size);
    ListItem* temp = h_table[hash_key]._first;

    while (temp->_name != searched)
    {
        compares++;
        temp = temp->_next;
        if (temp == nullptr)
        {
            std::cout << "There is no " << searched << " on position: " << hash_key<<"\n";
            return;
        }
    }
    compares++;
    refers++;
    std::cout << "Item " << searched << " is found on position: " << hash_key << "\n";
}


void delete_item(std::string searched, HashItem h_table[], const int& size, int& compares, int& refers)
{

    int hash_key = hashf_key(searched, size);
    ListItem* temp = h_table[hash_key]._first;
    ListItem* before = temp;

    if (temp != nullptr)
    {
        compares++;
        while (temp->_name != searched)
        {
            compares++;
            before = temp;
            temp = temp->_next;
            if (temp == nullptr)
            {
                std::cout << "There is no " << searched << " on position: " << hash_key << "\n";
                return;
            }
        }
        compares++;
       
        before->_next = temp->_next;
        if (temp == h_table[hash_key]._last)
        {
            h_table[hash_key]._last = before;
        }
        if (temp == h_table[hash_key]._first)
        {
            h_table[hash_key]._first = temp->_next;
        }
        delete temp;
    }
    else
    {
        std::cout << "There is no " << searched << " on position: " << hash_key << "\n";
    }


};

void mem_clear(HashItem h_table[], const int& size)
{
    ListItem* cur;
    ListItem* next;
    for (int i = 0; i < size; i++)
    {
        cur = h_table[i]._first;
        while (cur != nullptr)
        {
            next = cur->_next;
            delete cur;
            cur = next;
        }
    }
    delete[] h_table;
    h_table = nullptr;
}


enum Menu {
    MENU_INIT,
    MENU_SHOW,
    MENU_SRCH,
    MENU_ADD,
    MENU_DEL,
    MENU_EXIT

};

int main()
{
    std::string my_keys[10] = { "Anna", "Victor", "Diana", "TATyana", "Sergey", "MishA", "Nica","lesha", "Johnny", "AlexeY" };
    HashItem* hash_table = nullptr;
    std::string searched;
    std::string n_elem;
    srand(time(0));

    int compares = 0;
    int refs = 0;
    int size;

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
            << "\n| 0.Initialize your rand array.     |"
            << "\n| 1.Show non-sorted array.          |"
            << "\n| 2.Search element in h. table      |"
            << "\n| 3.Add new elem to h.table.        |"
            << "\n| 4.Delete elem. from h.table.      |"
            << "\n| 5.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_INIT:
            compares = 0;
            refs = 0;

            if (hash_table != nullptr)
            {
                mem_clear(hash_table, size);
            }

            std::cout << "Enter size of hash table (m > 10) :";
            std::cin >> size;
            while (size < 10)
            {
                std::cout << "Enter size more than 10!\nTry again: ";
                std::cin >> size;
            }

            hash_table = new HashItem[size];
            //for (int i = 0; i < 10; i++)
            //{
            //    hash_func(my_keys[i], hash_table, size, compares, refs);
            //}

            std::cout << "Hash table is initiallised with pre made keys!\n Compares: " << compares << " Refers: " << refs << std::endl;
            break;
        case MENU_SHOW:
            if (hash_table != nullptr)
            {
                show(hash_table, size);
            }
            else
            {
                std::cout << "Hash table is not initialised!";
            }
            break;
        case MENU_SRCH:
            compares = 0;
            refs = 0;
            std::cout << "Enter your string: ";
            std::cin >> searched;
            search(searched, hash_table, size, compares, refs);
            std::cout << "\n Compares : " << compares << std::endl;
            break;
        case MENU_ADD:
            compares = 0;
            refs = 0;
            std::cout << "Enter string of new elem: ";
            std::cin >> n_elem;
            hash_func(n_elem, hash_table, size, compares, refs);
            std::cout << "\n Compares : " << compares << " Refers : " << refs << std::endl;
            break;
        case MENU_DEL:
            compares = 0;
            refs = 0;
            std::cout << "Enter string of deleted elem: ";
            std::cin >> n_elem;
            delete_item(n_elem, hash_table, size, compares, refs);
            std::cout << "\n Compares : " << compares << " Refers : " << refs << std::endl;
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }

    mem_clear(hash_table, size);
    return 0;
}

