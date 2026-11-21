#include <cstddef>
#include <iostream>
#include <vector>

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

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> inorder;
  if (root == nullptr){
    return inorder;
  }
  TreeNode* curr = root;
  while(curr!=nullptr){
    if(curr->left==nullptr){
        inorder.push_back(curr->data);
        curr = curr->right;
    }
    else{
        TreeNode* prev = curr->left;
        while(prev->right!=nullptr && prev->right!=curr){
            prev = prev->right;
        }
        if(prev->right==nullptr){
            inorder.push_back(curr->data);
            prev->right = curr;
            curr = curr->left;
        }
        else{
            prev->right = nullptr;
            curr = curr->right;
        }
    }
  }
  return inorder;
}

int main() {
  TreeNode *head = new TreeNode(1);
  head->left = new TreeNode(2);
  head->left->left = new TreeNode(4);
  head->left->right = new TreeNode(5);
  head->left->right->left = new TreeNode(6);
  head->left->right->right = new TreeNode(7);
  head->right = new TreeNode(3);
  vector<int> inorder = preorderTraversal(head);
  cout << "[ ";
  for (int num : inorder) {
    cout << num << " ";
  }
  cout << "]";
  return 0;
};