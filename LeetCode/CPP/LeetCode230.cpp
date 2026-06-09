// Given the root of a binary search tree, and an integer k,
// return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Look For Reference In the Book On Pg No 88-89



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

int result;
int cnt = 1;

void inorderHelper(TreeNode* root, int k){
    if(root == nullptr) return;
    inorderHelper(root->left, k);
    if(cnt==k){
        result = root->val;
        return;
    }
    cnt++;
    inorderHelper(root->right, k);
};

int KthSmallest(TreeNode* root, int k){

    cnt=1;
    inorderHelper(root, k);
    return result;
};

int main(){
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(1);
    head->left->right = new TreeNode(2);
    head->right = new TreeNode(8);

    int k = 3;
    cout<<"Kth Smallest Element Is : "<<KthSmallest(head, k);
    return 0;
}