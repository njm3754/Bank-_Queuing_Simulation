#include "Queue.h"
#include <iostream>
#include <cstdlib>


    //CONSTRUCTOR
    Queue::Queue()
    {
       front =0;
       rear = CAPACITY-1;
       count = 0;
    }

    //ENQUEUE FUNCTION
    void Queue::enqueue(const Item& entry)
    {
        rear=find_next_index(rear);
        data[rear]=entry;
        ++count;
    }

    //DEQUEUE FUNCTION
    Queue::Item Queue::dequeue()
    {
        Item dequeued;
        dequeued = data[front];
        front = find_next_index(front);
        --count;
        return dequeued;
    }

    //FRIEND FUNCTION
    ostream& operator<<(ostream& out_s, Queue& q)
    {
        int dequeued
        int m =q.size_queue();

        for(int i=0; i<m; ++i)
        {
            dequeued=q.dequeue();
            out_s<<dequeued<< " ";
            q.enqueue(dequeued);

        }
        return out_s;
    }

