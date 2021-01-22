#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    Queue *my_queue = new Queue();
    cout << "my_queue->Front: " << my_queue->Front() << endl;

    my_queue->Enqueue(3);
    my_queue->Enqueue(6);

    cout << "my_queue->Front: " << my_queue->Front() << endl;



    return 0;
}