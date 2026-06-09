// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Look For Reference In the Book On Pg No 59-60


#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

void postorderHelper(TreeNode* root, vector<int>& result){
    if(root == nullptr) return;
    postorderHelper(root->left, result);
    postorderHelper(root->right, result);
    result.push_back(root->val);
};

vector<int> postorder(TreeNode* head){
    vector<int> result;
    postorderHelper(head, result);
    return result;
};

int main(){
    TreeNode* head = new TreeNode(2);
    head->left = new TreeNode(1);
    head->right = new TreeNode(3);
    vector<int> res = postorder(head);
    for(int num : res){
        cout<<num<<" ";
    }
}