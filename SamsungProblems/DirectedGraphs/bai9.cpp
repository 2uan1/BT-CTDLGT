#include <iostream>
#include <vector>

using namespace std;

void calculateInOut(vector<int> adjList[], int nodeCount, int inDegree[], int outDegree[]) {
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            outDegree[i]++;
            inDegree[adjList[i][j]]++;
        }
    }
}

void dfs(vector<int> adjList[], int nodeCount, int inDegree[], int outDegree[], int currentNode, vector<int> &cycle) {
    while (outDegree[currentNode] != 0) {
        int nextNode = adjList[currentNode].at(outDegree[currentNode] - 1);
        outDegree[currentNode]--;
        dfs(adjList, nodeCount, inDegree, outDegree, nextNode, cycle);
    }
    cycle.push_back(currentNode);
}

vector<int> getEulerianCycle(vector<int> adjList[], int nodeCount, int inDegree[], int outDegree[]) {
    vector<int> cycle;
    dfs(adjList, nodeCount, inDegree, outDegree, 0, cycle);
    return cycle;
}

int main() {
    int nodeCount, edgeCount;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodeCount >> edgeCount;
    int inDegree[nodeCount];
    int outDegree[nodeCount];
    for (int i = 0; i < nodeCount; i++) {
        inDegree[i] = 0;
        outDegree[i] = 0;
    }
    vector<int> adjList[nodeCount];
    for (int i = 0; i < edgeCount; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    calculateInOut(adjList, nodeCount, inDegree, outDegree);
    bool hasCycle = true;
    vector<int> output;
    if (hasCycle) {
        output = getEulerianCycle(adjList, nodeCount, inDegree, outDegree);
        if (output.size() != edgeCount + 1) {
            hasCycle = false;
        }
    }

    if (!hasCycle) {
        cout << "No Eulerian Cycle exist";
    } else {
        cout << "Eulerian Cycle: ";
        for (int i = 0; i < output.size(); i++) {
            cout << output[i] << " ";
        }
    }
    
    return 0;
}
