// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST
// is changed to the original key plus the sum of all keys greater than the original key in BST.

// As a reminder, a binary search tree is a tree that satisfies these constraints:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Look For Reference In the Book-2 On Pg No 70


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
    };
};

int sum = 0;

void dfs(TreeNode* head){
    if(head==nullptr){
        return;
    }
    dfs(head->right);
    sum+=head->val;
    head->val = sum;
    dfs(head->left);
};

TreeNode* BstToGst(TreeNode* head){
    dfs(head);
    return head;
};

void printTree(TreeNode* node){
    if(node==nullptr){
        return;
    }
    printTree(node->left);
    cout<<node->val<<" ";
    printTree(node->right);
};

int main(){
    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(1);
    head->left->left = new TreeNode(0);
    head->left->right = new TreeNode(2);
    head->left->right->right = new TreeNode(3);
    head->right = new TreeNode(6);
    head->right->left = new TreeNode(5);
    head->right->right = new TreeNode(7);
    head->right->right->right = new TreeNode(8);
    TreeNode* result = BstToGst(head);
    printTree(result);              //It should result in descending order values
    return 0;
};