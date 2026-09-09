#include <iostream>
#include <stack>
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

vector<int> inorderTraversal(TreeNode *root) {
  stack<TreeNode *> st;
  vector<int> inorder;
  TreeNode *node = root;
  while (true) {
    if (node != nullptr) {
      st.push(node);
      node = node->left;
    } else {
      if (st.empty()) {
        break;
      }
      node = st.top();
      st.pop();
      inorder.push_back(node->data);
      node = node->right;
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
  vector<int> inorder = inorderTraversal(head);
  cout << "[ ";
  for (int num : inorder) {
    cout << num << " ";
  }
  cout << "]";
  return 0;
};