#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int data_) {
        data = data_;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    Node* root = nullptr;
public:
    BinaryTree() {
        root = new Node();
    }

    BinaryTree(int data) {
        root = new Node();
    }
    
    void insertNode(int fatherNodeData, int childNodeData) {
        Node* fatherNode = findNode(root, fatherNodeData);
        if (fatherNode->left == nullptr) fatherNode->left = new Node(childNodeData);
        else fatherNode->right = new Node(childNodeData);
    }

    Node* findNode(Node* current, int value) {
        if (current == nullptr) return nullptr;
        else if (current->data == value) return current;
        Node* nodeFound = findNode(current->left, value);
        if (nodeFound == nullptr) nodeFound = findNode(current->right, value);
        return nodeFound;
    }

    void printInorder(Node* current) {
        if (current == nullptr) return;
        printInorder(current->left);
        cout << current->data << " ";
        printInorder(current->right);
    }

    int height(Node* current) {
        if (current == nullptr) return -1;
        return max(height(current->right), height(current->left)) + 1;
    }

    bool isBalanced(Node* current) {
        if (current == nullptr) return true;
        int leftHeight = height(current->left);
        int rightHeight = height(current->right);

        if (abs(leftHeight - rightHeight) <= 1 
        && isBalanced(current->left) 
        && isBalanced(current->right)) {
            return true;
        }
        return false;
    }

    Node* getRoot() {
        return root;
    }
};


int main(int argc, char const *argv[])
{
    //selection sort
    //balanced binary tree
    //connected component
    cout << "insert node count: ";
    int n;
    cin >> n;
    BinaryTree* bTree = new BinaryTree();
    for (int i = 0; i < n-1; i++) {
        int fatherNodeData, childNodeData;
        cin >> fatherNodeData >> childNodeData;
        bTree->insertNode(fatherNodeData, childNodeData);
    }
    // cout << "node = " << bTree->getRoot()->left->left->data << endl;
    // cout << "node = " << bTree->getRoot()->right->left->data << endl;
    bTree->printInorder(bTree->getRoot());
    if (bTree->isBalanced(bTree->getRoot())) {
        cout << "balanced" << endl;
    }
    else {
        cout << "unbalanced oh no!!!!" << endl;
    }
    // cout << "height = " << bTree->height(bTree->getRoot()->right);
    
    return 0;
}
