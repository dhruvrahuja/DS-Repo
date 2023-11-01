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
int main()
{
    node* root=NULL;
    root=buildtree(root);
    cout<<calculateHeight(root);
}