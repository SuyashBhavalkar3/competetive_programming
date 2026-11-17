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

bool Is_Same(TreeNode* node1, TreeNode* node2){
    if(node1==nullptr && node2==nullptr){
        return true;
    }
    if(node1==nullptr || node2==nullptr){
        return false;
    }
    if(node1->val!=node2->val){
        return false;
    }
    return Is_Same(node1->left, node2->left) && Is_Same(node1->right, node2->right);
}

int main(){
  TreeNode *node = new TreeNode(4);
  node->left = new TreeNode(9);
  node->right = new TreeNode(20);
  TreeNode *node2 = new TreeNode(3);
  node2->left = new TreeNode(9);
  node2->right = new TreeNode(20);
  bool isSame = Is_Same(node, node2);
  cout << "The Both Trees Are Identical : " << boolalpha<<isSame << endl;
  return 0;
}