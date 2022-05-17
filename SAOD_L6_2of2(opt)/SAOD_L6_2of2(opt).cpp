#include <iostream>
#include <string>

struct TNode
{
    char _name;
    TNode* _next;
    TNode* _prev;
};



struct TGraph
{   
    int _size = 0;
    std::string _names;
    int** _array = nullptr;
    TNode* _list = nullptr;

    TGraph(const int& size) : _size(size)
    {
        int** _array = new int*[size];
        for (size_t i = 0; i < size; i++)
        {
            _array[i] = new int[size];
        }

    }
};

    








int main()
{
    std::cout << "Hello World!\n";
}

