#include <iostream>
#include "MultidimensionalArray.h"

using namespace std;

MultidimensionalArray::MultidimensionalArray(int noOfDimensions, int sizesOfDimensions[])
{
    this->noOfDimensions = noOfDimensions;
    this->sizesOfDimensions = sizesOfDimensions;
    int totalSize = sizeof(int);
    for (int i = 0; i < noOfDimensions; i++)
    {
        totalSize *= sizesOfDimensions[i];
    }
    this->data = (int *)(malloc(totalSize));
}

uintptr_t MultidimensionalArray::getAddress(int indices[])
{
    int *indice = new int[this->noOfDimensions];
    for (int i = 0; i < this->noOfDimensions; i++)
    {
        indice[i] = indices[this->noOfDimensions - 1 - i];
    }
    int *sizes = new int[this->noOfDimensions];
    for (int i = 0; i < this->noOfDimensions; i++)
    {
        sizes[i] = this->sizesOfDimensions[this->noOfDimensions - 1 - i];
    }
    uintptr_t baseAddress = (uintptr_t)(this->data);
    int slot = 0;
    for (int i = 0; i <= this->noOfDimensions-1; i++)
    {
        int product = 1;
        for (int j = i+1; j <= this->noOfDimensions - 1; j++)
        {
            product *= sizes[j];
        }
        product *= indice[i];
        slot += product;
    }

    uintptr_t address = baseAddress + slot * sizeof(int);
    return address;
}

int MultidimensionalArray::getItem(int indices[])
{
    return *((int *)(this->getAddress(indices)));
}

void MultidimensionalArray::setItem(int item, int indices[])
{
    *((int *)(this->getAddress(indices))) = item;
}
