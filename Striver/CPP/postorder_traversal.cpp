#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int v){
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

void postOrderTraversal(TreeNode* root, vector<int>& postorder){
    if(root == nullptr){
        return;
    }
    postOrderTraversal(root->left, postorder);
    postOrderTraversal(root->right, postorder);
    postorder.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root){
    vector<int> postorder;
    postOrderTraversal(root, postorder);
    return postorder;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<int> res = postorderTraversal(root);
    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}