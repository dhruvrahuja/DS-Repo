#include<iostream>
#include<queue>
#include<map>
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
void topView(node* root) {
    if (root == NULL) return;

    map<int, int> m; // horizontal distance -> node data
    queue<pair<node*, int>> q; // node + horizontal distance

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<node*, int> p = q.front();
        node* n = p.first;
        int hd = p.second;
        q.pop();

        if (m.find(hd) == m.end()) {
            m[hd] = n->data;
        }

        if (n->left != NULL) q.push(make_pair(n->left, hd - 1));
        if (n->right != NULL) q.push(make_pair(n->right, hd + 1));
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }

    cout << endl;
}

void bottomView(node* root) {
    if (root == NULL) return;

    map<int, int> m; // horizontal distance -> node data
    queue<pair<node*, int>> q; // node + horizontal distance

    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<node*, int> p = q.front();
        node* n = p.first;
        int hd = p.second;
        q.pop();

        m[hd] = n->data;

        if (n->left != NULL) q.push(make_pair(n->left, hd - 1));
        if (n->right != NULL) q.push(make_pair(n->right, hd + 1));
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->second << " ";
    }

    cout << endl;
}

void leftView(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 1; i <= n; i++) {
            node* temp = q.front();
            q.pop();

            if (i == 1) {
                cout << temp->data << " ";
            }

            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
    }

    cout << endl;
}

void rightView(node* root) {
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 1; i <= n; i++) {
            node* temp = q.front();
            q.pop();

            if (i == n) {
                cout << temp->data << " ";
            }

            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
    }

    cout << endl;
}

int main()
{
    node* root=NULL;
    root=buildtree(root);
    cout << "Top View: ";
    topView(root);
    cout << "Bottom View: ";
    bottomView(root);
    cout << "Left View: ";
    leftView(root);
    cout << "Right View: ";
    rightView(root);
    return 0;
}
