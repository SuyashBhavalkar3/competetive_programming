#include <cstddef>
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

int Max_Depth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }
  int lh = Max_Depth(root->left);
  int rh = Max_Depth(root->right);
  return 1 + max(lh, rh);
}

int main() {
  TreeNode *node = new TreeNode(3);
  node->left = new TreeNode(9);
  node->right = new TreeNode(20);
  node->right->left = new TreeNode(15);
  node->right->right = new TreeNode(7);
  int max_depth = Max_Depth(node);
  cout << "The Maximum Depth Of Tree Is : " << max_depth << endl;
  return 0;
}