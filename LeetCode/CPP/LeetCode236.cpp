// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
// p and q as the lowest node in T that has both p and q as descendants
// (where we allow a node to be a descendant of itself).”


// Look For Reference In the Book On Pg No 112


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

TreeNode* find_lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root==nullptr||root==p||root==q) return root;
    TreeNode* left = find_lca(root->left, p, q);
    TreeNode* right = find_lca(root->right, p, q);
    if(left!=nullptr && right!=nullptr) return root;
    return (left!=nullptr) ? left : right;
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    TreeNode* lca = find_lca(root, root->left, root->right);
    cout<<"LCA Of Both The Nodes Is : "<<lca->val<<endl;
    return 0;
};