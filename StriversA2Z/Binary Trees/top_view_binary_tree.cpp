#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int v){
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> Top_View(TreeNode* root){
    if(root == nullptr){
        return {};
    }
    if(root->left==nullptr&&root->right==nullptr){
        return {root->val};
    }
    map<int, int> ordered_map;
    queue<pair<TreeNode*, int>> que;
    ordered_map[0] = root->val;
    que.push({root, 0});
    vector<int> ans;
    while(!que.empty()){
        int size = que.size();
        for(int i=0;i<size;i++){
            auto pairPopped = que.front();
            que.pop();
            TreeNode* poppedNode = pairPopped.first;
            int line = pairPopped.second;
            if(ordered_map.find(pairPopped.second)==ordered_map.end()){
                ordered_map[pairPopped.second] = pairPopped.first->val;
            }
            if(poppedNode->left!=nullptr){
                que.push({poppedNode->left, line-1});
            }
            if(poppedNode->right!=nullptr){
                que.push({poppedNode->right, line+1});
            }
        }
    }
    for(auto idx : ordered_map){
        ans.push_back(idx.second);
    }
    return ans;
}

int main(){
    TreeNode* node = new TreeNode(1);

    node->left = new TreeNode(2);
    node->right = new TreeNode(3);

    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);

    node->right->left = new TreeNode(6);
    node->right->right = new TreeNode(7);

    vector<int> topView = Top_View(node);

    for(int num : topView){
        cout<<num<<" ";
    }
    return 0;
}