// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root->

// The length of a path between two nodes is represented by the number of edges between them.

// Look For Reference In the Book On Pg No 128-129


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

int diameter = 0;

int height(TreeNode* root){
    if(root==nullptr)   return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    diameter = max(diameter, lh+rh);
    return 1+max(rh,lh);
};

int findDia(TreeNode* root){
    height(root);
    return diameter;
};

int main(){
    TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->right = new TreeNode(4);
        root->right->right = new TreeNode(5);
    cout<<"Max Diameter Is : "<<findDia(root);
    return 0;
}