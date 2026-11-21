#include <cstddef>
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

TreeNode *FindLastRight(TreeNode *root) {
  if (root->right == nullptr) {
    return root;
  }
  return FindLastRight(root->right);
}
TreeNode *helper(TreeNode *root) {
  if (root->right == nullptr) {
    return root->left;
  }
  if (root->left == nullptr) {
    return root->right;
  }
  TreeNode *rightChild = root->right;
  TreeNode *leftsRightestNode = FindLastRight(root->left);
  leftsRightestNode->right = rightChild;
  return root->left;
}
TreeNode *deleteNode(TreeNode *root, int key) {
  if (root == nullptr) {
    return nullptr;
  }
  if (root->val == key) {
    return helper(root);
  }
  TreeNode *curr = root;
  while (curr != nullptr) {
    if (curr->val > key) {
      if (curr->left != nullptr && curr->left->val == key) {
        curr->left = helper(curr->left);
        break;
      } else {
        curr = curr->left;
      }
    } else {
      if (curr->right != nullptr && curr->right->val == key) {
        curr->right = helper(curr->right);
        break;
      } else {
        curr = curr->right;
      }
    }
  }
  return root;
}

int main() {
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  TreeNode *nodeToInsert = new TreeNode(5);
  TreeNode *result = deleteNode(root, 5);
}