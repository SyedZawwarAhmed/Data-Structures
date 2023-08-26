#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList abc;
    abc.append(5);
    abc.append(4);
    abc.append(2);
    abc.append(7);
    abc.append(1);
    abc.print();
    return 0;
}