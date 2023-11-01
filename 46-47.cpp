#include<iostream>
#include<queue>
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
node* buildtree(node*root)
{
    cout<<"enter data ";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    {
        return NULL;
    }
    cout<<"enter left data of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"enter right data of "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
int calculateHeight(node* root)
{
    if (root == NULL) {
        return -1; // Height of an empty tree is -1
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}
int diameter(node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    int currentDiameter = leftHeight + rightHeight + 2; // Diameter passing through current node

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(currentDiameter, max(leftDiameter, rightDiameter));
}
int main()
{
    node* root=NULL;
    root=buildtree(root);
    cout<<"height is "<<calculateHeight(root)<<endl;
    cout<<"diameter is "<<diameter(root);
}