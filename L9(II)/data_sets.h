#pragma once
struct Item {
    int key;
    int inf;

};

struct Data
{
    Item* _array;
    int _size;

    Data(int size) : _size(size)
    {
        _array = new Item[size];
    }

};

struct ListNode
{
    Item _item;
    ListNode* _next;

    ListNode(){
        _next = nullptr;
    }

};
