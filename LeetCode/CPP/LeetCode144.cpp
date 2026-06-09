// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Look For Reference In the Book On Pg No 53-54

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

void helper(TreeNode* root, vector<int>& arr){
    if (root == nullptr){
        return;
    }
    arr.push_back(root->val);
    helper(root->left, arr);
    helper(root->right, arr);
};

vector<int> preorder(TreeNode* root){
    vector<int> arr;
    helper(root, arr);
    return arr;
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> res = preorder(root);
    for (int num : res){
        cout<<num<<" ";
    }
    return 0;
}