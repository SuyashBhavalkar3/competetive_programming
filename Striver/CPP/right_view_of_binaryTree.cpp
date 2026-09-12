#include <iostream>
#include <stack>
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

void rightView(TreeNode *root, vector<int> &res, int level,
               stack<TreeNode *> &stackst) {
  if (root == nullptr) {
    return;
  }
  if (stackst.size() == level) {
    res.push_back(root->val);
    stackst.push(root);
  }
  rightView(root->right, res, level + 1, stackst);
  rightView(root->left, res, level + 1, stackst);
}

vector<int> rightViewOfTree(TreeNode *root) {
  stack<TreeNode *> st;
  int level = 0;
  vector<int> res;
  rightView(root, res, level, st);
  return res;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->right = new TreeNode(7);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  vector<int> res = rightViewOfTree(root);
  for (int num : res) {
    cout << num << " ";
  }
  return 0;
}