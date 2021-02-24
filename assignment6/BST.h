#include "Node.h"

class BST {
    private: 
        Node *root;

    protected:
        Node *Insert(Node *new_node, int data);
        Node *FindMin(Node *node);
        Node *FindMax(Node *node);
        Node *Delete(Node *node, int data);
        void PrintPreOrder(Node *node);
        void PrintInOrder(Node *node);
        void PrintPostOrder(Node *node);
        void PrintLevelOrder(Node *node);

    public:
        BST();
        void Insert(int data);
        int FindMin();
        int FindMax();
        void Delete(int data);
        void PrintPreOrder();
        void PrintInOrder();
        void PrintPostOrder();
        void PrintLevelOrder();
        
};