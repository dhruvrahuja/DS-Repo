//61. Create a graph 
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<list<int> > adjacencyList;

public:
    Graph(int vertices) : numVertices(vertices), adjacencyList(vertices) {}
    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination);
        adjacencyList[destination].push_back(source);
    }
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (const auto& neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    cout << "Graph representation (Adjacency List):" << endl;
    graph.printGraph();

    return 0;
}