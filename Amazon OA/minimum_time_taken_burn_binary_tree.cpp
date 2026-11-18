#include <cstddef>
#include <iostream>
#include <queue>
#include <unordered_map>

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

TreeNode *Mark_Parents(TreeNode *root,
                       unordered_map<TreeNode *, TreeNode *> &parents_map,
                       int target) {
  queue<TreeNode *> que;
  que.push(root);
  TreeNode *targetNode;
  while (!que.empty()) {
    TreeNode *curr = que.front();
    if (curr->val == target) {
      targetNode = curr;
    }
    que.pop();
    if (curr->right != nullptr) {
      que.push(curr->right);
      parents_map[curr->right] = curr;
    }
    if (curr->left != nullptr) {
      que.push(curr->left);
      parents_map[curr->left] = curr;
    }
  }
  return targetNode;
}

int Find_Nodes_With_KDistance(TreeNode *root, int target) {
  if (root == nullptr) {
    return {};
  }
  unordered_map<TreeNode *, TreeNode *> parents_map;
  TreeNode *targetNode = Mark_Parents(root, parents_map, target);
  queue<TreeNode *> que;
  unordered_map<TreeNode *, bool> visitedNode;
  que.push(targetNode);
  visitedNode[targetNode] = true;
  int maxi = 0;
  while (!que.empty()) {
    int size = que.size();
    bool flag = false;
    for (int i = 0; i < size; i++) {
      TreeNode *curr = que.front();
      que.pop();
      if (curr->left != nullptr && visitedNode[curr->left] == false) {
        que.push(curr->left);
        visitedNode[curr->left] = true;
        flag = true;
      }
      if (curr->right != nullptr && visitedNode[curr->right] == false) {
        que.push(curr->right);
        visitedNode[curr->right] = true;
        flag = true;
      }
      if (parents_map[curr] != nullptr &&
          visitedNode[parents_map[curr]] == false) {
        que.push(parents_map[curr]);
        visitedNode[parents_map[curr]] = true;
        flag = true;
      }
    }
    if (flag == true) {
      maxi++;
    }
  }
  return maxi;
}

int main() {
  TreeNode *head = new TreeNode(3);

  head->left = new TreeNode(5);
  head->right = new TreeNode(1);

  head->left->left = new TreeNode(6);
  head->left->right = new TreeNode(2);

  head->right->left = new TreeNode(0);
  head->right->right = new TreeNode(8);

  head->left->right->left = new TreeNode(7);
  head->left->right->right = new TreeNode(4);

  int ans = Find_Nodes_With_KDistance(head, 2);
  cout << "The Minimum Time Taken To Burn The Tree Is : " << ans;
  return 0;
}