// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Look For Reference In the Book On Pg No 87


#include<iostream>

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


TreeNode* prevNode = nullptr;

bool helper(TreeNode* root){
    if(root == nullptr) return true;
    if(!helper(root->left)) return false;
    if(prevNode!=nullptr && prevNode->val>=root->val)   return false;
    prevNode = root;
    return helper(root->right);
};

bool isValidBST(TreeNode* root){
    return helper(root);
};

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    bool res = isValidBST(root);
    cout<<boolalpha;
    cout<<"Tree Is Validate : "<<res<<endl;
    return 0;
};