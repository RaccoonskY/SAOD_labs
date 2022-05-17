#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
//#include <cstdlib>


/*#1 LAB TASK (6-7) SECTION 1-2 */


///--------------------------------DYNAMIC QUEUE-----------------------------

template<typename T>
struct QueueNode{

    T q_item;
    QueueNode* q_next;
    QueueNode(T item):q_item(item)
    {

    }
};


template<typename T>
struct DynQueue
{
    QueueNode<T>* q_First;
    QueueNode<T>* q_Last;

    DynQueue()
    {
        q_First = new QueueNode<T>(NULL);
        q_First->q_next = nullptr;
        q_Last = q_First;
    }

};



template<typename T>
bool que_is_empty(DynQueue<T>& queue)
{
    if (queue.q_First->q_next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


template<typename T>
void show(DynQueue<T>& queue)
{
   QueueNode<T>* qTemp = queue.q_First->q_next;
   while (qTemp != nullptr)
   {
       std::cout << qTemp->q_item<<"--";
       qTemp = qTemp->q_next;
   }
   std::cout << std::endl;

}



template<typename T>
void add_elem(DynQueue<T>& queue, const T& item)
{
    QueueNode<T>* qTemp = new QueueNode<T>(item);
    qTemp->q_next = nullptr;
    queue.q_Last->q_next = qTemp;
    queue.q_Last = qTemp;
}


template<typename T>
void del_elem(DynQueue<T>& queue)
{
    if (!que_is_empty(queue))
    {
        QueueNode<T>* qTemp = queue.q_First->q_next;
        queue.q_First->q_next = qTemp->q_next;
        if (queue.q_First->q_next == nullptr)
        {
            queue.q_Last = queue.q_First;
        }
        std::cout << "\ndeleting: " << qTemp->q_item;
        qTemp->q_item = NULL;
        delete qTemp;
    }
    else
    {
        std::cout << "Queue is already empty!\n";
    }

}

template<typename T>
void mem_clear(DynQueue<T>& queue)
{
    while (queue.q_First->q_next != nullptr)
    {
        del_elem(queue);
    } 

   delete queue.q_First;
}


int rand_unit(int a) {

    return 1.0 + rand() % a;

}

template<typename T>
void random_action(DynQueue<T>& queue, int mode)
{   
    int random_choose = rand_unit(100) % 2;
    int rand_many_added, rand_many_deleted;
    switch (mode)
    {
    case 0:
        rand_many_added = rand_unit(3);
        rand_many_deleted = rand_many_added;
        break;
    case 1:
        rand_many_added = rand_unit(4);
        rand_many_deleted = rand_unit(3);
        break;
    case 2:
        rand_many_added = rand_unit(3);
        rand_many_deleted = rand_unit(4);
        break;
    default:
        break;
    }

    
    if (random_choose == 0)
    {
        std::cout << "\nAdding " << rand_many_added << " elements" << std::endl;
        for (size_t i = 0; i < rand_many_added; i++)
        {
            add_elem(queue, rand_unit(10));
        }
        
    }
    else
    {
        std::cout << "\nDeleting " << rand_many_added << " elements" << std::endl;
        for (size_t i = 0; i < rand_many_added; i++)
        {
            del_elem(queue);
        }
        
    }
    std::cout << "\nCURRENT QUEUE:\n";
    show(queue);
    Sleep(2000);
}


int main()
{
    srand(time(0));
    DynQueue<int> MyDQ = DynQueue<int>();
    bool program = true;
    int key = 0;
    int chosen_mode;

    while (program)
    {
         std::cout 
            << "\n_____________________________________";
        std::cout 
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 0.Amount added = amount deleted   |"
            << "\n| 1.Added more than deleted         |"
            << "\n| 2.Deleted more than added         |";
       std::cout
            << "\n_____________________________________" << std::endl;


        std::cin >> chosen_mode;

        if ((chosen_mode != 0 ) && (chosen_mode != 1) && (chosen_mode != 2))
        {
            std::cout << "\nChoose number from below ! You entered wrong number (0, 1, 2). ";
        }
        else
        {
            program = false;
        }
    }

    while (key != 'q')
    {
        random_action(MyDQ, chosen_mode);

        if (_kbhit()) {
            key = _getch();
        }
    }

    mem_clear(MyDQ);
    return 0;
}
