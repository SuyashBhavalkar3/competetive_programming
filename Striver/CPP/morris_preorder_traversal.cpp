#include <iostream>
#include <vector>
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

vector<int> morrisPreorder(TreeNode *root) {
  vector<int> result;
  TreeNode *curr = root;
  while (curr != nullptr) {
    if (curr->left == nullptr) {
      result.push_back(curr->val);
      curr = curr->right;
    } else {
      TreeNode *prev = curr->left;
      while (prev->right != nullptr && prev->right != curr) {
        prev = prev->right;
      }
      if (prev->right == nullptr) {
        prev->right = curr;
        result.push_back(curr->val);
        curr = curr->left;
      } else {
        prev->right = nullptr;
        curr = curr->right;
      }
    }
  }
  return result;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  vector<int> res = morrisPreorder(root);
  for (int num : res) {
    cout << num << " ";
  }
  return 0;
}