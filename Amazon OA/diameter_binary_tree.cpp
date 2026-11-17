#include <algorithm>
#include <cstddef>
#include <iostream>

using namespace std;

int diameter = 0;

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

int helper(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int lh = helper(root->left);
    int rh = helper(root->right);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int Max_Diameter(TreeNode *root){
    diameter = 0;
    helper(root);
    return diameter;
}

int main() {
  TreeNode *node = new TreeNode(3);
  node->left = new TreeNode(9);
  node->right = new TreeNode(20);
  node->right->left = new TreeNode(15);
  node->right->right = new TreeNode(7);
  int diameter = Max_Diameter(node);
  cout << "The Maximum Diameter Of Tree Is : " << diameter << endl;
  return 0;
}