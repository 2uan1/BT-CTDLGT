#include <iostream>
#include <vector>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    vector<Node> children;

public:
    Node() {
        fatherNode = nullptr;
        data = 0;
    }

    Node(int data_)
    {
        data = data_;
        fatherNode = nullptr;
    }

    void setData(int data_)
    {
        data = data_;
    }

    int getData()
    {
        return data;
    }

    vector<Node> getChildren()
    {
        return children;
    }

    void push(Node node)
    {
        children.push_back(node);
    }
    // Các hàm khởi tạo khác nếu cần thiết

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        root = new Node();
    }

    Tree(int data)
    {
        root = new Node(data);
    }

    Tree(Node* node)
    {
        root = node;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data)
    {
        Node* node = findNode(root, father);
        Node* newNode = new Node(data);
        root->push(*newNode);
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data)
    {
        Node* node = findNode(root, data);
        delete node;
    }


    Node* findNode(Node* father, int value)
    {
        if (father)
        {
            if (root->getData() == value) return root;
            for (int i = 0; i < root->getChildren().size(); i++)
            {
                findNode(root->getChildren().at(i), value);
            }
        }
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder()
    {
        cout << root->data << " ";
        for(int i = 0; i < root->getChildren().size(); i++)
        {
            Tree* childBranch = new Tree(root->getChildren().at(i));
            childBranch->preorder();
        }
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder()
    {
        for(int i = 0; i < root->getChildren().size(); i++)
        {
            Tree* childBranch = new Tree(root->getChildren().at(i));
            childBranch->preorder();
        }
        cout << root->data << " ";
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree()
    {
        if (root->getChildren().size > 2) return false;
        for (int i = 0; i < root->getChildren().size(); i++)
        {
            Tree* childBranch = new Tree(root->getChildren().at(i));
            childBranch->isBinaryTree();
        }
        return true;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree();

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder();

    // Hàm trả về độ cao của cây
    int height();

    // Hàm trả về độ sâu của một Node
    int depth(int data);

    // Hàm đếm số lượng lá
    int numOfLeaves();

    // Hàm trả về Node có giá trị lớn nhất
    int findMax();

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    // Test thử các hàm của lớp cây


    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại

    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}
