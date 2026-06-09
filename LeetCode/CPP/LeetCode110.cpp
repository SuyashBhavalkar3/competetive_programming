// Given a binary tree, determine if it is height-balanced.

// Look For Reference In the Book-2 On Pg No 12


#include<iostream>
#include<vector>
#include<algorithm>

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

bool has_same_height = true;

int checkHeight(TreeNode* root){
    if(root == nullptr) return 0;
    int lh = checkHeight(root->left);
    int rh = checkHeight(root->right);
    if(abs(lh-rh)>1){
        has_same_height = false;
    }
    return 1 + max(lh, rh);
}

bool isHeightSame(TreeNode* root){
    checkHeight(root);
    return has_same_height;
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(20);
    cout<<boolalpha;
    cout<<"Tree Has Balanced Height : "<<isHeightSame(root)<<endl;
    return 0;
}