#include "Node.h"

class Queue {
    private:
        Node *front;
        Node *rear;

    public:
        Queue();
        void Enqueue(int new_value);
        int Dequeue();
        int Front(); //"peek"
        void isEmpty();

       
};