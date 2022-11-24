#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

int getVerticesOrEdges(string text, int stopIndex)
{
    int multiplier = 1;
    int integer = 0;
    for (int i = text.size() - 1; i >= stopIndex; i--)
    {
        integer += (text[i] - 48) * multiplier;
        multiplier *= 10;
    }
    return integer;
}

int getX(string text)
{
    int multiplier = 1;
    int integer = 0;
    int start = 0;
    for (int i = text.size() - 1; i >= 0; i--)
    {
        if (text[i] == ',') {
            start++;
            i--;
        }
        if (start >= 2)
        {
            integer += (text[i] - 48) * multiplier;
            multiplier *= 10;
        }
    }
    return integer;
}

int getY(string text)
{
    int multiplier = 1;
    int integer = 0;
    int start = 0;
    for (int i = text.size() - 1; i >= 0; i--)
    {
        if (text[i] == ',') {
            start++;
            i--;
        }

        if (start >= 2)
            break;

        if (start >= 1)
        {
            integer += (text[i] - 48) * multiplier;
            multiplier *= 10;
        }
    }
    return integer;
}

int getWeight(string text)
{
    int multiplier = 1;
    int integer = 0;
    for (int i = text.size() - 1; i >= 0; i--)
    {
        if (text[i] == ',')
            break;

        integer += (text[i] - 48) * multiplier;
        multiplier *= 10;
    }
    return integer;
}

int main()
{
    string myText;

    ifstream MyReadFile("data.txt");

    getline(MyReadFile, myText);
    int numberOfVertices = getVerticesOrEdges(myText, 2);
    getline(MyReadFile, myText);
    int numberOfEdges = getVerticesOrEdges(myText, 2);

    int vertices[] = {0, 1, 2, 3, 4, 5, 6};
    Graph graph(numberOfVertices, vertices);
    while (getline(MyReadFile, myText)) {
        graph.insert(getX(myText), getY(myText), getWeight(myText));
    }
    graph.print();
    MyReadFile.close();
    graph.getShortestPath(1, 5);
    return 0;
}