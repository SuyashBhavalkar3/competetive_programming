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

vector<int> preorderTraversal(TreeNode *root) {
  stack<TreeNode *> st;
  vector<int> preorder;
  TreeNode *node = root;
  while (true) {
    if (node != nullptr) {
      st.push(node);
      preorder.push_back(node->val);
      node = node->left;
    } else {
      if (st.empty()) {
        break;
      }
      TreeNode *nodeTop = st.top();
      st.pop();
      node = nodeTop->right;
    }
  }
  return preorder;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  vector<int> res = preorderTraversal(root);
  for (int num : res) {
    cout << num << " ";
  }
  return 0;
}