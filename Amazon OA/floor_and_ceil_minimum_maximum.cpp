#include <iostream>
using namespace std;

struct TreeNode {
  TreeNode *left;
  TreeNode *right;
  int val;
  TreeNode(int v) {
    val = v;
    left = nullptr;
    right = nullptr;
  }
};

int Find_Floor(TreeNode* root, int key){
    int val = -1;
    TreeNode* curr = root;
    while(curr!=nullptr){
        if(curr->val<=key){
            val = curr->val;
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return val;
}

int Find_Ceil(TreeNode* root, int key){
    int val = -1;
    TreeNode* curr = root;
    while(curr!=nullptr){
        if(curr->val>=key){
            val = curr->val;
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return val;
}

int Find_Minimum(TreeNode* root){
    TreeNode* curr = root;
    while(curr->left!=nullptr){
        curr = curr->left;
    }
    return curr->val;
}

int Find_Maximum(TreeNode* root){
    TreeNode* curr = root;
    while(curr->right!=nullptr){
        curr = curr->right;
    }
    return curr->val;
}

int main() {
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(4);
  root->right = new TreeNode(12);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(6);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(14);
  int key = 7;
  int floor = Find_Floor(root, key);
  int ceil = Find_Ceil(root, key);
  int minimum = Find_Minimum(root);
  int maximum = Find_Maximum(root);
  cout<<"The Ceil And Floor Values For The Given Key And Minimum And Maximum Of BST Are "<<floor<<", "<<ceil<<", "<<minimum<<", "<<maximum<<" Respectively"<<endl;
}