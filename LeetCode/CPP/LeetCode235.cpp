// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in
// T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Look For Reference In the Book On Pg No 110


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
    if(root==nullptr)   return nullptr;
    if(p->val<root->val&&q->val<root->val){
        return find_lca(root->left, p, q);
    }
    if(p->val>root->val&&q->val>root->val){
        return find_lca(root->right, p, q);
    }
    return root;
}

int main(){
    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(3);
    head->right = new TreeNode(7);
    TreeNode* p = head->left;
    TreeNode* q = head->right;
    cout<<"The LCA Is : "<<find_lca(head, p, q)->val<<endl;
    return 0;
}