class Graph
{
  int **adjacencyMatrix;
  int numberOfVertices;
  int *vertices;

public:
  Graph(int numberOfVertices, const int vertices[]);
  void insert(int x, int y, int weight = 1);
  void print();
  int* getShortestPath(int source, int destination);
  int* getMinimumSpanningTree();
};