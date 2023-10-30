#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int nodeA;
    int nodeB;
    int weight;

    Edge(int a, int b, int weight_) {
        nodeA = a;
        nodeB = b;
        weight = weight_;
    }
};

class Compare {
    public:
    bool operator()(Edge a, Edge b) {
        if (a.weight < b.weight) {
            return false;
        }
        return true;
    }
};

void prim(vector<Edge> list[], int prev[], int size) {
    priority_queue<Edge, vector<Edge>, Compare> queue;
    bool visited[size] = {false};
    visited[0] = true;
    int totalCost = 0;
    vector<Edge> shortest;
    //choose 1 as starting vertex
    visited[1] = true;
    //enqueuing first vertex edges
    for (int i = 0; i < list[1].size(); i++) {
        queue.push(list[1].at(i));
    }
    while(queue.empty() == false) {
        if (visited[queue.top().nodeB] == false) {
            visited[queue.top().nodeB] = true;
            shortest.push_back(queue.top());
            totalCost += queue.top().weight;
        }
        //enqueue more nodes
        int indexOfNewlyAddedNode = queue.top().nodeB;
        queue.pop();
        for (int i = 0; i < list[indexOfNewlyAddedNode].size(); i++) {
            if (visited[list[indexOfNewlyAddedNode].at(i).nodeB] == false) {
                queue.push(list[indexOfNewlyAddedNode].at(i));
            }
        }
    }

    cout << totalCost << endl;
    for (int i = 0; i < shortest.size(); i++) {
        cout << shortest.at(i).nodeA << " " << shortest.at(i).nodeB << " " << shortest.at(i).weight << endl;
    }
}

int main(int argc, char const *argv[])
{
    int nodeCount, edgeCount;
    cout << "enter node count and edge count: ";
    cin >> nodeCount >> edgeCount;
    // 1 index
    nodeCount++;
    vector<Edge> adjacentNodeList[nodeCount];
    int prev[nodeCount];
    for (int i = 0; i < edgeCount; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        Edge* uEdge= new Edge(u, v, weight);
        Edge* vEdge = new Edge(v, u, weight);
        adjacentNodeList[u].push_back(*uEdge);
        adjacentNodeList[v].push_back(*vEdge);
    }
    for (int i = 1; i < nodeCount; i++) {
        cout << "Node " << i << " adjacent edges are: ";
        for (int j = 0; j < adjacentNodeList[i].size(); j++) {
            cout << adjacentNodeList[i].at(j).nodeB << " ";
        }
        cout << endl;
    }

    prim(adjacentNodeList, prev, nodeCount);

    // vector<Edge> test;
    // priority_queue<Edge, vector<Edge>, Compare> queue;
    // Edge* testNode1 = new Edge(4, 5);
    // Edge* testNode2 = new Edge(3, 2);
    // Edge* testNode3 = new Edge(2, 10);
    // Edge* testNode4 = new Edge(1, 3);
    // queue.push(*testNode1);
    // queue.push(*testNode2);
    // queue.push(*testNode3);
    // queue.push(*testNode4);

    // while (queue.empty() == false) {
    //     cout << "num = " << queue.top().nodeNumber << endl;
    //     queue.pop();
    // }

    return 0;
}
