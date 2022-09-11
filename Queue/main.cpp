#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
  Queue queue(5);
    queue.enqueue(4);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(6);
    queue.enqueue(5);
    queue.dequeue();
    queue.enqueue(9);
    queue.print();
  return 0;  
}