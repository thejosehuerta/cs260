#include "Node.h"

class BST {
    private: 
        Node *root;

    protected:
        Node *Insert(Node *new_node, int data);
        void InOrderPrint(Node *node);

    public:
        BST();
        void Insert(int data);
        void InOrderPrint();
        
};