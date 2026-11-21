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

TreeNode *INsert_Node(TreeNode *root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }
  TreeNode *curr = root;
  while (curr != NULL) {
    if (curr->val > val) {
      if (curr->left == NULL) {
        curr->left = new TreeNode(val);
        break;
      } else {
        curr = curr->left;
      }
    } else {
      if (curr->right == NULL) {
        curr->right = new TreeNode(val);
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
  TreeNode *result = INsert_Node(root, 5);
}