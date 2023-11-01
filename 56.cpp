//56. Converting preorder from post order
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    TreeNode* buildFromPostorder( vector<int> postorder, int& postIndex) {
        if (postIndex < 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postIndex]);
        postIndex--;
        root->right = buildFromPostorder(postorder, postIndex);
        root->left = buildFromPostorder(postorder, postIndex);
        return root;
    }

    void preorderTraversal(TreeNode* current) const {
        if (current != nullptr) {
            cout << current->data << " ";
            preorderTraversal(current->left);
            preorderTraversal(current->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}
    void convertPostorderToPreorder(vector<int> postorder) {
        int postIndex = postorder.size() - 1;
        root = buildFromPostorder(postorder, postIndex);
    }

    void preorderTraversal() const {
        preorderTraversal(root);
        cout << endl;
    }
};

vector<int> vec(int a[],int n){
    vector<int> r;
    for(int i=0;i<n;i++){
        r.push_back(a[i]);
    }
    return r;
}

int main() {
    int po[8]={4, 5, 2, 8, 6, 7, 3, 1};

    vector<int> postorder = vec(po,8);
    
    BinaryTree binaryTree;
    binaryTree.convertPostorderToPreorder(postorder);

    cout << "Preorder Traversal: ";
    binaryTree.preorderTraversal();

    return 0;
}