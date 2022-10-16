#include <iostream>
#include <windows.h>
#include "Graph.h"

using namespace std;

Graph::Graph(int numberOfVertices, const int vertices[])
{
    this->numberOfVertices = numberOfVertices;
    this->vertices = new int[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        this->vertices[i] = vertices[i];
    }
    this->adjacencyMatrix = new int *[numberOfVertices];

    for (int i = 0; i < numberOfVertices; i++)
    {
        this->adjacencyMatrix[i] = new int[numberOfVertices];
    }

    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            this->adjacencyMatrix[i][j] = 0;
        }
    }
}

void Graph::insert(int x, int y, int weight)
{
    this->adjacencyMatrix[x][y] = weight;
}

void Graph::print()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            if (this->adjacencyMatrix[i][j] == 0)
            {
                SetConsoleTextAttribute(h, 7);
            }
            else
            {
                SetConsoleTextAttribute(h, 11);
            }
                cout << this->adjacencyMatrix[i][j] << " ";
        }
        SetConsoleTextAttribute(h, 7);

        cout << endl;
    }
}