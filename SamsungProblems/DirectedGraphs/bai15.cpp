// kahn's topological sort algorithm
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