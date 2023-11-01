#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int data)
        {
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
node* insert(node* root, int data)
{
    if(root == NULL)
    {
        return new node(data);
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
node* buildBST(node* root)
{
    cout << "Enter data (Enter -1 to stop): ";
    int data;
    cin >> data;
    while(data != -1)
    {
        root = insert(root, data);
        cout << "Enter data (Enter -1 to stop): ";
        cin >> data;
    }
    return root;
}
node* findNode(node* root, int data)
{
    if(root == NULL || root->data == data)
    {
        return root;
    }
    if(data < root->data)
    {
        return findNode(root->left, data);
    }
    return findNode(root->right, data);
}
node* findMin(node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
node* deleteNode(node* root, int data)
{
    if(root == NULL)
    {
        return root;
    }
    if(data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if(root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node* root = NULL;
    root = buildBST(root);

    int valueToFind;
    cout << "Enter value to search for: ";
    cin >> valueToFind;

    node* foundNode = findNode(root, valueToFind);

    if(foundNode != NULL)
    {
        cout << "Value " << valueToFind << " found in the tree." << endl;
    }
    else
    {
        cout << "Value " << valueToFind << " not found in the tree." << endl;
    }
    int valueToDelete;
    cout << "Enter value to delete: ";
    cin >> valueToDelete;
    root = deleteNode(root, valueToDelete);
    cout << "Inorder Traversal after deletion: ";
    inorder(root);
    cout << endl;
    return 0;
}
