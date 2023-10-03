class BinarySearchTree{
private:
    Node* root;
public:
    

    BinarySearchTree()
    {
        root = nullptr;
    }

    BinarySearchTree(int data)
    {
        root = new Node(data);
    }

    void removeMax()
    {
        Node* cur = root;
        while(cur->right->right != nullptr)
        {
            cur = cur->right;
        }
        Node* nodeToBeDeleted = cur->right;
        if (nodeToBeDeleted->left == nullptr)
        {
            cur->right = nullptr;
            delete nodeToBeDeleted;
        }
        else
        {
            cur->right = nodeToBeDeleted->left;
            delete nodeToBeDeleted;
        }
    }

    void removeMin()
    {
        Node* cur = root;
        while(cur->left->left != nullptr)
        {
            cur = cur->left;
        }
        Node* nodeToBeDeleted = cur->left;
        if (nodeToBeDeleted->right == nullptr)
        {
            cur->left= nullptr;
            delete nodeToBeDeleted;
        }
        else
        {
            cur->left = nodeToBeDeleted->right;
            delete nodeToBeDeleted;
        }
    }
};