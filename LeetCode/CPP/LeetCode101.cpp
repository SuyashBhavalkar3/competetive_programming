// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Look For Reference In the Book On Pg No 74-75

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

bool checkValues(TreeNode* leftN, TreeNode* rightN){
    if(leftN==nullptr&&rightN==nullptr)    return true;
    if(leftN==nullptr || rightN==nullptr)   return false;
    if(leftN->val!=rightN->val) return false;
    return ((checkValues(leftN->left, rightN->right))&&(checkValues(leftN->right, rightN->left)));
};

bool isSame(TreeNode* root){
    return checkValues(root->left, root->right);
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    bool res = isSame(root);
    cout<<boolalpha;
    cout<<"The Tree Is Symmetric : "<<res;
};