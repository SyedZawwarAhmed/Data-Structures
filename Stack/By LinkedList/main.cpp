#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stack;

    stack.push(3);
    stack.push(5);
    stack.push(2);
    stack.push(8);
    stack.pop();
    stack.pop();
    stack.push(0);
    stack.push(4);

    stack.print();

    cout << "Top of stack: " << stack.getTop() << endl;

  return 0;  
}