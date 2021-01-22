#include "Node.h"

class Queue {
    private:
        Node *front;
        Node *rear;

    public:
        Queue();
        bool isEmpty();
        void Enqueue(int new_value);
        void Dequeue();
        int Front();   
};