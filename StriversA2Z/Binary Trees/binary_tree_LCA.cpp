#include <cstddef>
#include <iostream>
#include <ostream>

using namespace std;

struct TreeNode {
  TreeNode *left;
  TreeNode *right;
  int data;
  TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

TreeNode* Find_LCA(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == nullptr || root == p || root == q){
        return root;
    }
    TreeNode* left = Find_LCA(root->left, p, q);
    TreeNode* right = Find_LCA(root->right, p, q);
    if(left!=nullptr && right!=nullptr){
        return root;
    }
    if(left!=nullptr){
        return left;
    }
    return right;
}

int main(){
    TreeNode* head = new TreeNode(3);

    head->left = new TreeNode(5);
    head->right = new TreeNode(1);

    head->left->left = new TreeNode(6);
    head->left->right = new TreeNode(2);

    head->right->left = new TreeNode(0);
    head->right->right = new TreeNode(8);

    head->left->right->left = new TreeNode(7);
    head->left->right->right = new TreeNode(4);

    TreeNode* p = head->left->left;
    TreeNode* q = head->right->left;

    TreeNode* LCA = Find_LCA(head, p, q);
    
    cout<<"The LCA of Node P and Node Q are : "<<LCA->data<<endl;
    return 0;
}