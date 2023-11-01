#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter data: ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new node(data);
    cout << "Enter left data of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right data of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

node* findLCA(node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

int main() {
    node* root = NULL;
    root = buildTree(root);
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    int n1, n2;
    cout << "Enter two nodes to find LCA: ";
    cin >> n1 >> n2;

    node* lca = findLCA(root, n1, n2);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "Nodes not found in the tree." << endl;
    }

    return 0;
}
