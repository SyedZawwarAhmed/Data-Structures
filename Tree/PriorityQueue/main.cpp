#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {
    PriorityQueue queue(9);
    int data[] = {4, 1, 8, 2, 4, 5, 2, 6 , 7};
    for (const int &item: data) {
        queue.enqueue(item);
    }
    queue.dequeue();
    queue.print();
    return 0;
}