//63. Dfs
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int> > adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); 
    }

    void dfs(int startNode) {
        vector<bool> visited(vertices, false);
        stack<int> s;
        s.push(startNode);

        while (!s.empty()) {
            int currentNode = s.top();
            s.pop();

            if (!visited[currentNode]) {
                cout << currentNode << " ";
                visited[currentNode] = true;

                for (int neighbor : adjacencyList[currentNode]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }

        cout << endl;
    }
    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (const auto& neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);

    cout << "Graph representation (Adjacency List):" << endl;
    graph.printGraph();

    cout << "DFS starting from node 0: ";
    graph.dfs(0);

    return 0;
}