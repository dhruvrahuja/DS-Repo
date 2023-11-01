//60. Binary expression tree
#include <iostream>
#include <stack>
#include <string>
#include<vector>
using namespace std;

struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    TreeNode* root;
    bool isOperand(const string& token) {
        return (token.size() == 1 && isalnum(token[0]));
    }
    TreeNode* constructTree(const vector<string>& postfix) {
        stack<TreeNode*> st;
        for (const string& token : postfix) {
            if (isOperand(token)) {
                st.push(new TreeNode(token));
            } else {
                TreeNode* operand2 = st.top();
                st.pop();
                TreeNode* operand1 = st.top();
                st.pop();

                TreeNode* newNode = new TreeNode(token);
                newNode->left = operand1;
                newNode->right = operand2;

                st.push(newNode);
            }
        }

        return st.top();
    }
    void inorderTraversal(TreeNode* current) const {
        if (current != nullptr) {
            inorderTraversal(current->left);
            cout << current->value << " ";
            inorderTraversal(current->right);
        }
    }

public:
    ExpressionTree() : root(nullptr) {}
    void buildTree(const vector<string>& postfix) {
        root = constructTree(postfix);
    }
    void inorderTraversal() const {
        inorderTraversal(root);
        cout << endl;
    }
};

vector<string> vec(string a[],int n){
    vector<string> r;
    for(int i=0;i<n;i++){
        r.push_back(a[i]);
    }
    return r;
}

int main() {
    string a[]={"2", "3", "4", "*", "+"};
    vector<string> postfixExpression = vec(a,5);

    ExpressionTree expressionTree;
    expressionTree.buildTree(postfixExpression);

    cout << "Inorder Traversal of the Expression Tree: ";
    expressionTree.inorderTraversal();

    return 0;
}