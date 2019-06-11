#include <iostream>
#include <list>

using namespace std;

class Graph {
    int numberofvertices;
    list<int> *adjacencyList;
    void recurvisited(int vertex, bool visited[]);

    public:
        Graph(int noofvertices);
        void addEdge(int vertex, int weight);
        void DFSearch(int vertex);
};

Graph::Graph(int noofvertices) {
    this->numberofvertices = noofvertices;
    this->adjacencyList = new list<int>[noofvertices];
}

void Graph::addEdge(int vertex, int weight) {
    adjacencyList[vertex].push_back(weight);
}

void Graph::recurvisited(int vertex, bool visited[]) {
    visited[vertex] = true;

    cout << "Visiting " << vertex << endl;

    list<int>::iterator i;
    for(i = adjacencyList[vertex].begin(); i != adjacencyList[vertex].end(); ++i) {
        if(!visited[*i])
            recurvisited(*i, visited);
    }
}

void Graph::DFSearch(int vertex) {
    bool *visited = new bool[this->numberofvertices];
    for(int i=0; i<this->numberofvertices; i++) {
        visited[i] = false;
    }

    recurvisited(vertex, visited);
}

int main() {
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    graph.DFSearch(0);

    return(0);
}
