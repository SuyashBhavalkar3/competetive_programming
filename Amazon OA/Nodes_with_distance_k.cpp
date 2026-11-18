#include <cstddef>
#include <iostream>
#include <queue>
#include <unordered_map>
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

void Mark_Parents(TreeNode *root,
                  unordered_map<TreeNode *, TreeNode *> &parents_map) {
  queue<TreeNode *> que;
  que.push(root);
  while (!que.empty()) {
    TreeNode *curr = que.front();
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
}

vector<int> Find_Nodes_With_KDistance(TreeNode *root, TreeNode *target, int k) {
  if (root == nullptr) {
    return {};
  }
  unordered_map<TreeNode *, TreeNode *> parents_map;
  Mark_Parents(root, parents_map);
  queue<TreeNode *> que;
  unordered_map<TreeNode *, bool> visitedNode;
  visitedNode[target] = true;
  que.push(target);
  int currK = 0;
  while (currK < k) {
    int size = que.size();
    for (int i = 0; i < size; i++) {
      TreeNode *curr = que.front();
      que.pop();
      if (curr->left != nullptr && visitedNode[curr->left] == false) {
        que.push(curr->left);
        visitedNode[curr->left] = true;
      }
      if (curr->right != nullptr && visitedNode[curr->right] == false) {
        que.push(curr->right);
        visitedNode[curr->right] = true;
      }
      if (parents_map[curr] != nullptr &&
          visitedNode[parents_map[curr]] == false) {
        que.push(parents_map[curr]);
        visitedNode[parents_map[curr]] = true;
      }
    }
    currK++;
  }
  vector<int> ans;
  while (!que.empty()) {
    ans.push_back(que.front()->val);
    que.pop();
  }
  return ans;
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

  vector<int> ans = Find_Nodes_With_KDistance(head, head->left, 2);
  for (int num : ans) {
    cout << num << " ";
  }
  return 0;
}