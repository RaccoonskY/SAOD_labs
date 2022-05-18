#include <iostream>
#include <ctime>
#include <string>


int rand_int() {

    int randi = 0 + rand() % 100;
    return randi;

}

int hashf_key(std::string str)
{
    int hash_key = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        hash_key += (int)str[i];
    }
    hash_key = hash_key % 10;
    return hash_key;
}


void hash_func(std::string str, std::string hash_table[])
{
    int hash_key = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        hash_key += (int)str[i];
    }
    hash_key = hash_key % 10;
    hash_table[hash_key] = str;
};

void hash_func(std::string keys[], std::string hash_table[])
{
    int hash_key;   
    for (size_t i = 0; i < 10; i++)
    {
        hash_key = hashf_key(keys[i]);
        hash_table[hash_key] = keys[i];
    }
    
  
};

void show(std::string h_table[], const int& size)
{
    std::cout << "HASH TABLE: \n";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "I(" << i << "): " << h_table[i] << std::endl;
    }
}

void search(std::string searched, std::string h_table[])
{
    int h_key = hashf_key(searched);
    if (h_table[h_key] == searched)
    {
        std::cout << "Element is found on position: " << h_key << "\n";
    }
    else
    {
        
        std::cout << "There is no such element! ;( Your h.key is "<<h_key << "\n";
    }
}

enum Menu {
    MENU_INIT,
    MENU_SHOW,
    MENU_SRCH,
    MENU_EXIT

};

int main()
{
    std::string my_keys[10] = { "Anna", "Victor", "Diana", "TATyana", "Sergey", "MishA", "Nica","lesha", "Johnny", "AlexeY" };
    std::string hash_table[10];
    std::string searched;
    srand(time(0));
    
    int compares = 0;
    int refs = 0;
    int size = 10;

    bool program = true;
    int chosen;
    int init_mode = 0;
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
            << "\n| 3.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_INIT:
            hash_func(my_keys, hash_table);
            init_mode = 1;
            break;
        case MENU_SHOW:
            if (init_mode == 1)
            {
                show(hash_table, size);
            }
            else
            {
                std::cout << "Hash table is not initialised!";
            }
            break;
        case MENU_SRCH:
            std::cout << "Enter your string: ";
            std::cin >> searched;
            search(searched, hash_table);
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }

    return 0;
}

