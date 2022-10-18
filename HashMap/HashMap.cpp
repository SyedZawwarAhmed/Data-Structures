#include <iostream>
#include "HashMap.h"
// #include "LinkedList.h"

using namespace std;

HashMap::HashMap(int hashSize)
{
    this->hashSize = hashSize;
    this->data = new LinkedList[hashSize];
}

void HashMap::insert(int item)
{
    int hashIndex = item % this->hashSize;
    this->data[hashIndex].append(item);
}

int HashMap::find(int item)
{
    int hashIndex = item % this->hashSize;

    if (this->data[hashIndex].find(item))
        return hashIndex; 
    else 
        return false;
}

void HashMap::print() {
    for (int i=0; i< this->hashSize; i++) {
        this->data[i].print();
    }
}