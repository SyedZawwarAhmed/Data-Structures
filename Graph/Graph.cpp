#include <iostream>
#include <limits>
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

struct Vertex
{
    int index;
    bool known = false;
    int distance = numeric_limits<int>::max();;
    int previousVertex = -1;
    int outdegree;
    int *adjacentVertices;
};

int *Graph::getShortestPath(int vertex)
{

    Vertex **vertices = new Vertex *[this->numberOfVertices];

    for (int i = 0; i < this->numberOfVertices; i++)
    {
        vertices[i] = new Vertex;
    }

    for (int i = 0; i < this->numberOfVertices; i++)
    {
        vertices[i]->index = i;
        int outdegree = 0;
        for (int j = 0; j < this->numberOfVertices; j++)
        {
            if (this->adjacencyMatrix[i][j] != 0)
                outdegree++;
        }
        vertices[i]->outdegree = outdegree;

        vertices[i]->adjacentVertices = new int[vertices[i]->outdegree];
        int adjacentVerticesCount = 0;
        for (int j = 0; j < this->numberOfVertices; j++)
        {
            if (this->adjacencyMatrix[i][j] > 0)
            {
                vertices[i]->adjacentVertices[adjacentVerticesCount++] = j;
            }
        }
    }

    for (int i = 0; i < numberOfVertices; i++)
    {
        if (vertices[i]->outdegree > 0)
        {
            vertices[i]->distance = 0;
            break;
        }
    }

    for (int i = 0; i < this->numberOfVertices; i++)
    {
        int minimumDistance = numeric_limits<int>::max();;
        int vertexSelected;
        for (int j = 0; j < this->numberOfVertices; j++)
        {
            if (vertices[j]->distance < minimumDistance && vertices[j]->known == false)
            {
                vertices[j]->known = true;
                minimumDistance = vertices[j]->distance;
                vertexSelected = j;
                break;
            }
        }
        for (int j = 0; j < vertices[vertexSelected]->outdegree; j++)
        {
            int selectedVertexDistance = vertices[vertexSelected]->distance;
            int weight = adjacencyMatrix[vertexSelected][vertices[vertexSelected]->adjacentVertices[j]];
            int currentDistance = vertices[vertices[vertexSelected]->adjacentVertices[j]]->distance;
            if (currentDistance > selectedVertexDistance + weight)
            {
                vertices[vertices[vertexSelected]->adjacentVertices[j]]->distance = selectedVertexDistance + weight;
                vertices[vertices[vertexSelected]->adjacentVertices[j]]->previousVertex = vertexSelected;
            }
        }
    }

    int previousVerticesCount = 0;
    int previousVertex = vertices[vertex]->previousVertex;
    while (previousVertex > -1)
    {
        previousVertex = vertices[previousVertex]->previousVertex;
        previousVerticesCount++;
    }
    int previousVerticesCountBackup = previousVerticesCount + 1;
    previousVertex = vertices[vertex]->previousVertex;
    int *shortestPath = new int[previousVerticesCountBackup];
    shortestPath[previousVerticesCount] = vertex;
    while (previousVertex > -1)
    {
        shortestPath[--previousVerticesCount] = previousVertex;
        previousVertex = vertices[previousVertex]->previousVertex;
    }

    cout << "The Shortest Path from Source is:- ";
    for (int i = 0; i < previousVerticesCountBackup; i++)
    {
        cout << shortestPath[i] << " ";
    }
    cout << endl;
    return shortestPath;
}