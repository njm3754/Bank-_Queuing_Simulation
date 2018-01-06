#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <cstdlib>

using namespace std;


    class Queue
    {
        public:
          // MEMBER CONSTANT
          typedef int Item;
          static const int CAPACITY = 100;

          // CONSTRUCTOR
          Queue( );

          // MODIFICATION MEMBER FUNCTIONS
          void enqueue ( const Item& entry );
          Item dequeue ( );

          // CONSTANT MEMBER FUNCTIONS
          int size_queue( ) const { return count; }
          bool check_if_empty( ) const { return count == 0; }

          // FRIEND FUNCTION
          friend std::ostream& operator << ( std::ostream& out_s, Queue q );

        private:

          // DATA MEMBERS
          Item data[CAPACITY];         // Holds the Queue's Items
          int front;           // Index of the front of the Queue
          int rear;            // Index of the rear of the Queue
          int count;           // Current length of the Queue

          // PRIVATE MEMBER FUNCTION
          int find_next_index ( int i )const{ return (i+1) % CAPACITY; }
    };

#endif // QUEUE_H
