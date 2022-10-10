#include <iostream>
#include "MultidimensionalArray.h"

using namespace std;

MultidimensionalArray::MultidimensionalArray(int noOfDimensions, int sizesOfDimensions[]) {
    this->noOfDimensions = noOfDimensions;
    this->sizesOfDimensions = sizesOfDimensions;
    int totalSize = sizeof(int);
    for (int i=0; i<noOfDimensions; i++) {
        totalSize *= sizesOfDimensions[i];
    }
    this->data = (int*)(malloc(totalSize));
}

int MultidimensionalArray::getAddress(int indices[]) {
    uintptr_t baseAddress = (uintptr_t)(this->data);
    int slot = 0;
    for (int i=0; i<this->noOfDimensions; i++) {
        int product = 1;
        for (int j=i+1; j<this->noOfDimensions; j++) {
            product *= this->sizesOfDimensions[j];
        }
        product *= indices[i];
        slot += product;
    }
    // int baseAddress = 640000;
    int address = baseAddress + slot*sizeof(int);
    return address;
}

int MultidimensionalArray::getItem(int indices[]) {
    return *((int*)(this->getAddress(indices)));
}

void MultidimensionalArray::setItem(int item, int indices[]) {
    *((int*)(this->getAddress(indices))) = item;
}

