#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node() {
        value = 0;
        next = nullptr;
    }

    Node(int value_) {
        value = value_;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = new Node();
    }

    LinkedList(int data) {
        head = new Node(data);
    }

    void insertNode(int data) {
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = new Node(data);
    }

    void printList() {
        Node* cur = head;
        while (cur != nullptr) {
            cout << cur->value << "->";
            cur = cur->next;
        }
    }

    int get(int index) {
        Node* cur = head;
        for (int i = 0; i < index+1; i++) {
            cur = cur->next;
        }
        return cur->value;
    }

    int size() {
        Node* cur = head;
        int nodeCount = 0;
        while(cur->next != nullptr) {
            nodeCount++;
            cur = cur->next;
        }
        return nodeCount;
    }
};

int getConnectedComponentCount(LinkedList arr[], int nodeCount) {
    queue<int> nodeToVisit;
    bool visited[nodeCount+1] = {false};
    visited[0] = true;
    int connectedComponentCount = 0;
    int index = 0;
    while (index < nodeCount+1) {
        if (visited[index] == false) {
            visited[index] = true;
            nodeToVisit.push(index);
        }

        //if a numebr has been inserted into the queue
        if (nodeToVisit.empty() == false) {
            // while loop to run dfs through entire connected component
            while (nodeToVisit.empty() == false) {
                int frontNodeNeighbourCount = arr[nodeToVisit.front()].size();
                if (visited[nodeToVisit.front()] == false) {
                    visited[nodeToVisit.front()] = true;
                }
                for (int i = 0; i < frontNodeNeighbourCount; i++) {
                    if (visited[arr[nodeToVisit.front()].get(i)] == false) {
                        nodeToVisit.push(arr[nodeToVisit.front()].get(i));
                    }
                }
                nodeToVisit.pop();
            }
            connectedComponentCount++;
            index = 0;
        }

        index++;
    }
    return connectedComponentCount;
}

int main () {
    int n, m;
    cin >> n >> m;
    LinkedList nodes[n+1];
    for (int i = 0; i < m; i++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        nodes[nodeA].insertNode(nodeB);
        nodes[nodeB].insertNode(nodeA);
    }
    for (int i = 0; i < n+1; i++) {
        nodes[i].printList();
        cout << endl;
    }
    cout << getConnectedComponentCount(nodes, n) << endl;
}