//58. Avl tree creation insertion 
#include <iostream>
#include <algorithm>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>
class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalance(AVLNode* node) {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    AVLNode* insert(AVLNode* node, int key) {
        if (node == nullptr) {
            return new AVLNode(key);
        }

        if (key < node->data) {
            node->left = insert(node->left, key);
        } else if (key > node->data) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->data) {
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->data) {
            return leftRotate(node);
        }
        if (balance > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void inorderTraversal(AVLNode* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}
    void insert(int key) {
        root = insert(root, key);
    }
    void inorderTraversal() const {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree<int> avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);

    cout << "Inorder Traversal: ";
    avlTree.inorderTraversal();

    return 0;
}