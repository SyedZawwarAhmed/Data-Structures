#include <iostream>

using namespace std;

struct Vertex {
    int index;
    bool known = false;
    unsigned int distance = (unsigned int)~0;
    int previousVertex = -1;
    int outdegree;
    int *adjacentVertices;
};

int main() {
    Vertex** vertices = new Vertex*[7];

    for (int i = 0; i < 7; i++) {
        vertices[i] = new Vertex;
    }
    cout << vertices[5]->previousVertex << endl;
    return 0;
}