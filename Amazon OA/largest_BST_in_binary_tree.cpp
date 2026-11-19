#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct NodeInfo {
  int minValue;
  int maxValue;
  int maxSize;
  NodeInfo(int min, int max, int size) {
    minValue = min;
    maxValue = max;
    maxSize = size;
  }
};

NodeInfo maxBSTHelper(TreeNode *root) {
  if (root == nullptr) {
    return NodeInfo(INT_MAX, INT_MIN, 0);
  }
  auto left = maxBSTHelper(root->left);
  auto right = maxBSTHelper(root->right);
  if (left.maxValue < root->val && root->val < right.minValue) {
    return NodeInfo(min(left.minValue, root->val),
                    max(right.maxValue, root->val),
                    left.maxSize + right.maxSize + 1);
  }
  return NodeInfo(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int Find_Max_BST(TreeNode *root) { return maxBSTHelper(root).maxSize; }

int main() {
  TreeNode *root = new TreeNode(20);
  root->left = new TreeNode(15);
  root->right = new TreeNode(40);
  root->left->left = new TreeNode(14);
  root->left->right = new TreeNode(18);
  root->left->left->right = new TreeNode(17);
  root->left->right->left = new TreeNode(16);
  root->left->right->right = new TreeNode(19);
  root->right->left = new TreeNode(30);
  root->right->right = new TreeNode(60);
  root->right->right->left = new TreeNode(50);
  int maxSizeBSTinBT = Find_Max_BST(root);
  cout << "The Largest BST Size in Binary Tree Is : " << maxSizeBSTinBT << endl;
  return 0;
}