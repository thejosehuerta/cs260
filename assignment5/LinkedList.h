#include "Node.h"

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList();
        void Insert(int data);
        void Remove(int n);
        void Delete(int data);
        void Search(int data);
        int Retrieve(int n);
        void Print();
        int Count();
};