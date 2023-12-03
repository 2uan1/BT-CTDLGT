#include <iostream>
#include <vector>

using namespace std;

int countParallel(vector<int> adjList[], int nodeCount) {
    int parallelCount[nodeCount][nodeCount];
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < nodeCount; j++) {
            parallelCount[i][j] = 0;
        }
    }
    for (int i = 0; i < nodeCount; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            parallelCount[i][adjList[i][j]]++;
            parallelCount[adjList[i][j]][i]++;
        }
    }
    int count = 0;
    for (int i = 0; i < nodeCount; i++) {
        for (int j = i+1; j < nodeCount; j++) {
            if (parallelCount[i][j] > 2) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int nodeCount, edgeCount;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodeCount >> edgeCount;
    vector<int> adjList[nodeCount];
    for (int i = 0; i < edgeCount; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int count = countParallel(adjList, nodeCount);
    cout << "number of parallel edges are " << count;
    return 0;
}
