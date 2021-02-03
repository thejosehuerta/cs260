#include "Node.h"

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList();
        void Insert(int data, int n);
        void Remove(int n);
        int Retrieve(int n);
        void Print();
        int Count();
};