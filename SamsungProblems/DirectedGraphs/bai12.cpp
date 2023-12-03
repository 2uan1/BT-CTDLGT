#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void calculateInOut(vector<int> adjList[], int nodeCount, int inDegree[], int outDegree[]) {
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            outDegree[i]++;
            inDegree[adjList[i][j]]++;
        }
    }
}

void kahn(vector<int> adjList[], int nodeCount, int inDegree[], int order[]) {
    queue<int> queue;
    for (int i = 0; i < nodeCount; i++) {
        if (inDegree[i] == 0) queue.push(i);
    }
    int index = 0;
    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();
        order[index++] = currentNode;
        for (int i = 0; i < adjList[currentNode].size(); i++) {
            inDegree[adjList[currentNode][i]]--;
            if (inDegree[adjList[currentNode][i]] == 0) {
                queue.push(adjList[currentNode][i]);
            }
        }
    }
}

bool hasSingleTopologicalOrder(vector<int> adjList[], int nodeCount, int inDegree[], int order[]) {
    kahn(adjList, nodeCount, inDegree, order);
    for (int i = 0; i < nodeCount-1; i++) {
        bool hasPath = false;
        for (int j = 0; j < adjList[order[i]].size(); j++) {
            if (adjList[order[i]][j] == order[i+1]) {
                hasPath = true;
                break;
            }
        }
        if (hasPath == false) return false;
    }
    return true;
}

int main() {
    int nodeCount, edgeCount;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodeCount >> edgeCount;
    int inDegree[nodeCount];
    int outDegree[nodeCount];
    int order[nodeCount];
    for (int i = 0; i < nodeCount; i++) {
        inDegree[i] = 0;
        outDegree[i] = 0;
        order[i] = 0;
    }
    vector<int> adjList[nodeCount];
    for (int i = 0; i < edgeCount; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    calculateInOut(adjList, nodeCount, inDegree, outDegree);
    if (hasSingleTopologicalOrder(adjList, nodeCount, inDegree, order)) cout << "has single topological order";
    else cout << "has many topological order";

    return 0;
}