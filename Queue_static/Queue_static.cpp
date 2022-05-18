#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
//#include <cstdlib>


/*#1 LAB TASK (5-7) SECTION 1-2 */




///--------------------------------STATIC QUEUE-----------------------------
template<typename T>
struct Queue {

    int q_size = 5;
    int q_queue[5];
    int q_last = 0;
    int q_first = 0;
    int q_count = 0;


};



template<typename T>
bool que_is_empty(Queue<T>& que) {
    if (que.q_count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
bool que_is_full(Queue<T>& que) {
    if (que.q_count == que.q_size && que.q_count != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


template<typename T>
void add_elem(Queue<T>& que, const T& elem)
{
    if (!que_is_full(que))
    {
        que.q_queue[que.q_last] = elem;
        que.q_last++;
        if (que.q_last == que.q_size)
        {
            que.q_last = 0;
        }
        que.q_count++;
    }
    else {
        std::cout << "\nYour queue is full! Delete element or clear whole queue!" << std::endl;
    }

}

template<typename T>
void del_elem(Queue<T>& que)
{
    if (que.q_count != 0)
    {
        que.q_queue[que.q_first] = NULL;
        que.q_first++;
        if (que.q_first == que.q_size)
        {
            que.q_first = 0;
        }
        que.q_count--;
    }
    else
    {
        std::cout << "\n Your queue is empty, add elem before deleting! " << std::endl;
    }

}





template<typename T>
void show(Queue<T>& que)
{
    int cur;

    if (que.q_count > 0)
    {
        std::cout << "\nCurrent queue: \n";
        cur = que.q_first;
        do
        {
            std::cout << que.q_queue[cur] << "---";
            if (cur == que.q_size - 1)
            {
                cur = 0;
            }
            else
            {
                cur = cur + 1;
            }
        } while (cur != que.q_last);


    }
    std::cout << std::endl;


}

template<typename T>
void mem_clear(Queue<T>& que)
{

    que.q_count = NULL;
    que.q_first = NULL;
    que.q_last = NULL;

}


enum Menu {
    MENU_INIT,
    MENU_ADDN,
    MENU_SHST,
    MENU_DEL,
    MENU_EXIT

};

int main()
{
    srand(time(0));

 

    Queue<int> queue;
    bool program = true;
    int chosen;
    int stage = 0;//stage = 0 - stack is not initiallized, stage = 1 - stack is made


    while (program)
    {
        std::cout
            << "\n_____________________________________";
        std::cout
            << "\n| Choose what you want from menu:   |";
        std::cout
            << "\n|___________________________________|";
        std::cout
            << "\n| 0.Initialization of queue         |"
            << "\n| 1.Add new element to your queue.  |"
            << "\n| 2.Show current queue              |"
            << "\n| 3.Delete one element of queue     |"
            << "\n| 4.EXIT.                           |";
        std::cout
            << "\n_____________________________________" << std::endl;
        std::cin >> chosen;

        switch (chosen)
        {
        case MENU_INIT:
            if (stage == 0)
            {
                std::cout << "\n QUEUE IS INITIALLISED!.";
                queue = Queue<int>();
                stage = 1;
            }
            else
            {
                std::cout << "\n Stack is already initialized, please clear data to reinitiallizing !";
            }
            break;


        case MENU_ADDN:
            if (stage == 1)
            {
                if (que_is_full(queue))
                {
                    std::cout << "\nCurrent queue is FULL! ";
                }
                else
                {
                    int numb_add;
                    std::cout << "\nEnter number to add to queue: ";
                    std::cin >> numb_add;
                    add_elem(queue, numb_add);
                }
            }
            else
            {
                std::cout << "\nPlease, initialize stack first !";
            }
            break;

        case MENU_SHST:
            if (stage == 1)
            {
                show(queue);
            }
            else
            {
                std::cout << "\nPlease, initialize stack first !";
            }
            break;


        case MENU_DEL:
            if (stage == 1)
            {   
                if (que_is_empty(queue))
                {
                    std::cout << "\nCurrent queue is empty!";
                }
                else
                {
                    del_elem(queue);
                }
            }
            else
            {
                std::cout << "\nPlease, initialize stack first !";
            }
            break;

        case MENU_EXIT:
            std::cout << "EXIT!";
            program = false;
            break;


        default:
            std::cout << "\nUnknown command";
            break;
        }
    }



    mem_clear(queue);
}

