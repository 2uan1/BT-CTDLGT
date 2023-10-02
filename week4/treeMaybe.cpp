#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* firstChild;
    Node* secondChild;
    Node* thirdChild;

    Node()
    {
        data = 1;
        firstChild = nullptr;
        secondChild = nullptr;
        thirdChild = nullptr;
    }

    Node(int data_)
    {
        data = data_;
        firstChild = nullptr;
        secondChild = nullptr;
        thirdChild = nullptr;
    }

    friend class Tree;
};

class Tree{
private:

public:
    Node* root;

    Tree(Node* node)
    {
        root = node;
    }

    Tree()
    {
        root = new Node();
    }

    Tree(int data)
    {
        root = new Node(data);
    }

    bool insert(int father, int data_)
    {
        if (!contains(father))
        {
            cout << "fatherNode = " << findNode(father) << endl;
            cout << "tree doesnt contain " << father << endl;
//            cout << "unable to insert " << father << " " << data_ << endl;
            return false;
        }
        Node* fatherNode = findNode(father);
        if (fatherNode->firstChild == nullptr)
        {
            fatherNode->firstChild = new Node(data_);
            return true;
        }
        else if (fatherNode->secondChild == nullptr)
        {
            fatherNode->secondChild = new Node(data_);
            return true;
        }
        else if (fatherNode->thirdChild == nullptr)
        {
            fatherNode->thirdChild = new Node(data_);
            return true;
        }
        if (fatherNode->firstChild->data == data_ || fatherNode->secondChild->data == data_ || fatherNode->thirdChild->data == data_) return false;
    }

    int remove(int data_)
    {

    }

    void preorder()
    {
        if (root == nullptr) return;
        cout << root->data << "     ";
//        return;

        if (root->firstChild != nullptr)
        {
            Tree* firstBranch = new Tree(root->firstChild);
            firstBranch->preorder();
        }

        if (root->secondChild != nullptr)
        {
            Tree* secondBranch = new Tree(root->secondChild);
            secondBranch->preorder();
        }

        if (root->thirdChild != nullptr)
        {
            Tree* thirdBranch = new Tree(root->thirdChild);
            thirdBranch->preorder();
        }
    }

    void postorder()
    {

    }

    void inorder()
    {

    }

    Node* findNode(int data_)
    {
        if (root->data == data_)
        {
            return root;
        }
        else
        {
            if (root->firstChild != nullptr)
            {
                Tree* firstChildBranch = new Tree(root->firstChild);
                firstChildBranch->findNode(data_);
            }
            if (root->secondChild != nullptr)
            {
                Tree* secondChildBranch = new Tree(root->secondChild);
                secondChildBranch->findNode(data_);
            }
            if (root->thirdChild != nullptr)
            {
                Tree* thirdChildBranch = new Tree(root->thirdChild);
                thirdChildBranch->findNode(data_);
            }
        }
    }

    bool contains(int value)
    {
        Node* tmp = findNode(value);
        if (tmp == nullptr) return false;
        else return true;
    }
};

int main()
{
    int n, m;// # of nodes and of edges
    cin >> n >> m;
    Tree* dumbTree = new Tree();
//    dumbTree->root->firstChild = new Node(2);
//    dumbTree->root->secondChild= new Node(4);
//    dumbTree->root->thirdChild = new Node(7);
//    dumbTree->root->firstChild->firstChild = new Node(3);
//    dumbTree->root->firstChild->secondChild = new Node(5);
//    dumbTree->root->secondChild->firstChild = new Node(6);
//    dumbTree->root->thirdChild->firstChild = new Node(9);
//    dumbTree->root->thirdChild->secondChild = new Node(12);
//    dumbTree->preorder();
    for (int i = 0; i < m; i++)
    {
        int fatherData, childData;
        cin >> fatherData >> childData;
        if(!dumbTree->insert(fatherData, childData))
        {
            cout << "unable to insert " << fatherData << " " << childData << endl;
        }
    }
    cout << dumbTree->root->secondChild->secondChild << "    ssss         ";
    dumbTree->preorder();
}
