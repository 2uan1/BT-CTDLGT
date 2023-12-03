#include <iostream>
#include <list>
#include <vector>

using namespace std;

void addEdge(vector<list<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool isEdgeConnectedUtil(const vector<list<int>>& graph, int u, int parent, vector<bool>& visited,
                         vector<int>& disc, vector<int>& low) {
    static int time = 0;
    int children = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : graph[u]) {
        if (!visited[v]) {
            children++;
            if (isEdgeConnectedUtil(graph, v, u, visited, disc, low))
                return true;

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                return true;
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }

    return false;
}

bool isEdgeConnected(const vector<list<int>>& graph, int vertices) {
    vector<bool> visited(vertices, false);
    vector<int> disc(vertices, 0);
    vector<int> low(vertices, 0);

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i] && isEdgeConnectedUtil(graph, i, -1, visited, disc, low))
            return false;
    }

    return true;
}

int main() {
    int nodeCount, edgeCount;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodeCount >> edgeCount;
    vector<list<int>> graph(nodeCount);
    for (int i = 0; i < edgeCount; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }    

    if (isEdgeConnected(graph, nodeCount)) {
        cout << "The graph is edge connected." << endl;
    } else {
        cout << "The graph is not edge connected." << endl;
    }

    return 0;
}