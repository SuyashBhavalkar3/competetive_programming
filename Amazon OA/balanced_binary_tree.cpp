#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ios>
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

int Balanced_Helper(TreeNode* node){
    if(node == nullptr){
        return 0;
    }
    int lh = Balanced_Helper(node->left);
    if(lh == -1){
        return -1;
    }
    int rh = Balanced_Helper(node->right);
    if(rh == -1){
        return -1;
    }
    if(abs(lh - rh)>1){
        return -1;
    }
    return 1 + max(lh, rh);
}

bool Is_Balanced(TreeNode *root) {
  return Balanced_Helper(root)!=-1;
}

int main() {
  TreeNode *node = new TreeNode(3);
  node->left = new TreeNode(9);
  node->right = new TreeNode(20);
  node->right->left = new TreeNode(15);
  node->right->right = new TreeNode(7);
  bool balanced = Is_Balanced(node);
  cout << "The Maximum Depth Of Tree Is : " <<boolalpha<< balanced << endl;
  return 0;
}