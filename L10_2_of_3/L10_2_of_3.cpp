#include <iostream>
#include <ctime>
#include <string>


int rand_int() {

    int randi = 0 + rand() % 100;
    return randi;

}

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


void hash_func(std::string str, std::string hash_table[],const int& m, int& compares, int& refers)
{

    int hash_key = hashf_key(str, m);
    int i = 0;
    int j = (hash_key + i) % m;
    while (hash_table[j] != "" && i < m)
    {
        i++;
        j = (hash_key + i) % m;
        compares++;

    }
    
    if (hash_table[j] == "")
    {
        hash_table[j] = str;
        refers++;
    }
    else
    {
        std::cout << "No appropriate place for '"<<str<<"' !"<<"\nOriginal key is " << hash_key << "\nLast key is " << j<<std::endl;
    }
    compares+=1;

};

void hash_func(std::string keys[], std::string hash_table[],const int& m, int& compares, int& refers)
{
    int hash_key;
    for (size_t i = 0; i < 10; i++)
    {
        hash_func(keys[i], hash_table, m, compares, refers);
    }


};

void table_add(std::string table[], std::string _new, const int& m, int& compares, int& refers)
{
    int h_key =hashf_key(_new, m);

}


void show(std::string h_table[], const int& size)
{
    std::cout << "HASH TABLE: \n";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "I(" << i << "): " << h_table[i] << std::endl;
    }
}

void search(std::string searched, std::string h_table[], const int& size, int& compares, int& refers)
{
    int h_key = hashf_key(searched, size);
    int i = 0;
    int j = (h_key + i) % size;
    while (h_table[j] != searched && i < size)
    {
        i++;
        compares++;
        j = (h_key + i) % size;
    }
    
    if (h_table[j] == searched)
    {
        std::cout << "Element " << searched << " is found with\noriginal key: "<<h_key<<" and cur. position: "<< j << std::endl;
        
    }
    else
    {
        std::cout << "There is no such element in table !";
    }
    compares++;

}

enum Menu {
    MENU_INIT,
    MENU_SHOW,
    MENU_SRCH,
    MENU_ADD,
    MENU_EXIT

};

int main()
{
    std::string my_keys[10] = { "Anna", "Victor", "Diana", "TATyana", "Sergey", "MishA", "Nica","lesha", "Johnny", "AlexeY" };
    std::string* hash_table = nullptr;
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
            << "\n| 1.Show array.                     |"
            << "\n| 2.Search element in h. table      |"
            << "\n| 3.Add new elem to h.table.        |"
            << "\n| 4.EXIT.                           |";
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
                delete[] hash_table;
            }
      
            std::cout << "Enter size of hash table (m > 10) :";
            std::cin >> size;
            while (size < 10)
            {
                std::cout << "Enter size more than 10!\nTry again: ";
                std::cin >> size;
            }

            hash_table = new std::string[size];
            hash_func(my_keys, hash_table, size, compares, refs);

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
            std::cout <<"\n Compares : " << compares << " Refers : " << refs << std::endl;
            break;
        case MENU_EXIT:
            program = false;
            break;
        }

    }
    
    delete[] hash_table;
    return 0;
}

