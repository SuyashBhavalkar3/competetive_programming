// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Look For Reference In the Book On Pg No 42-43


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

void inorderHelper(TreeNode* root, vector<int>& result){
    if(root == nullptr) return;
    inorderHelper(root->left, result);
    result.push_back(root->val);
    inorderHelper(root->right, result);
};

vector<int> inorder(TreeNode* head){
    vector<int> result;
    inorderHelper(head, result);
    return result;
};

int main(){
    TreeNode* head = new TreeNode(2);
    head->left = new TreeNode(1);
    head->right = new TreeNode(3);
    vector<int> res = inorder(head);
    for(int num : res){
        cout<<num<<" ";
    }
}