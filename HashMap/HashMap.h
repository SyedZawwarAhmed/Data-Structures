#include "LinkedList.h"

class HashMap {
    int hashSize;
    LinkedList *data;
    public:
    HashMap(int hashSize);
    void insert(int item);
    int find(int item);
    void print();
};