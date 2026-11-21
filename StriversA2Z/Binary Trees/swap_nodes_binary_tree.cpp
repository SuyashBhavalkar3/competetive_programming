#include <cstddef>
#include <utility>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *prevNode;
TreeNode *first;
TreeNode *middle;
TreeNode *last;

void helper(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  helper(root->left);
  if (prevNode != nullptr && prevNode->val > root->val) {
    if (first == nullptr) {
      first = prevNode;
      middle = root;
    } else {
      last = root;
    }
  }
  prevNode = root;
  helper(root->right);
}

void Make_BST(TreeNode *root) {
  prevNode = nullptr;
  first = nullptr;
  middle = nullptr;
  last = nullptr;
  helper(root);
  if (first != nullptr && last != nullptr) {
    swap(first->val, last->val);
  } else if (first != nullptr && middle != nullptr) {
    swap(first->val, middle->val);
  }
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->right->left = new TreeNode(2);
  Make_BST(root);
  return 0;
}