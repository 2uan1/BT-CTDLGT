#include <iostream>
#include <vector>

using namespace std;

void listWorkOrder(vector<int> list[], int size) {
    bool done[size] = {false};
    done[0] = true;
    int printCount = 0;
    // -1 cause 1 index
    while (printCount < size-1) {
        for (int i = 1; i < size; i++) {
            
            // check if node number i is in any nodes' list
            if (done[i] == false) {

                bool doAble = true;
                for (int j = 1; j < size; j++) {
                    if (done[j] == false) {
                        for (int k = 0; k < list[j].size(); k++) {
                            if (list[j].at(k) == i) doAble = false;
                        }
                    }
                }

                if (doAble) {
                    done[i] = true;
                    cout <<  i << " ";
                    printCount++;
                }
            }
        }
    }
}

int main() {
    int nodeCount, edgeCount;
    cout << "enter node count and edge count: ";
    cin >> nodeCount >> edgeCount;
    //cause for 1 index
    nodeCount++;
    vector<int> adjacentNodeList[nodeCount];
    for (int i = 0; i < edgeCount; i++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adjacentNodeList[nodeA].push_back(nodeB);
    }

    // for (int i = 1; i < nodeCount; i++) {
    //     cout << "node " << i << " is adjacent to ";
    //     for (int j = 0; j < adjacentNodeList[i].size(); j++) {
    //         cout << adjacentNodeList[i].at(j) << " ";
    //     }
    //     cout << endl;
    // }
    
    listWorkOrder(adjacentNodeList, nodeCount);
    
    return 0;
}