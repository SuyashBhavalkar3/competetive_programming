// Given the root of a Binary Search Tree (BST),
// return the minimum absolute difference between the values of any two different nodes in the tree.

// Look For Reference In the Book On Pg No 65-66

#include<iostream>
#include<optional>
#include<algorithm>
#include<climits>

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

int minDiff = INT_MAX;
optional<int> prevValue;

void inorder(TreeNode* root){
    if(root == nullptr) return;
    inorder(root->left);
    if(prevValue.has_value()){
        minDiff = min(minDiff, root->val-prevValue.value());
    }
    prevValue = root->val;
    inorder(root->right);
}

int findAbsMin(TreeNode* root){
    inorder(root);
    return minDiff;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);
    cout<<"Min Abs Distance Is : "<<findAbsMin(root)<<endl;
}