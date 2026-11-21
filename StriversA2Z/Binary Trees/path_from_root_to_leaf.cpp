#include <cstddef>
#include <iostream>
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

void preorder_helper(TreeNode* root, vector<vector<int>>& allpaths, vector<int>& currPath){
    if(root == nullptr){
        return;
    }
    currPath.push_back(root->data);
    if(root!=nullptr && root->left==nullptr && root->right==nullptr){
        allpaths.push_back(currPath);
        currPath.pop_back();
        return;
    }
    else {
        preorder_helper(root->left, allpaths, currPath);
        preorder_helper(root->right, allpaths, currPath);
    }
    currPath.pop_back();
}

vector<vector<int>> Path_Root_To_Leaf(TreeNode *root) {
    vector<vector<int>> paths;
    if(root==nullptr){
        return paths;
    }
    vector<int> path;
    preorder_helper(root, paths, path);
    return paths;
}

int main() {
  TreeNode *head = new TreeNode(1);
  head->left = new TreeNode(2);
  head->left->left = new TreeNode(4);
  head->left->right = new TreeNode(5);
  head->left->right->left = new TreeNode(6);
  head->left->right->right = new TreeNode(7);
  head->right = new TreeNode(3);
  vector<vector<int>> paths  = Path_Root_To_Leaf(head);
  cout<<"{";
  for(vector<int> path : paths){
    cout<<"{";
    for(int num : path){
        cout<<num<<" ";
    }
    cout<<"} ";
  }
  return 0;
};