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

vector<int> Bottom_VIew(TreeNode* root){
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
                ordered_map[pairPopped.second] = pairPopped.first->val;
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
    TreeNode* node = new TreeNode(20);

    node->left = new TreeNode(8);
    node->right = new TreeNode(22);

    node->left->left = new TreeNode(5);
    node->left->right = new TreeNode(3);

    node->right->right = new TreeNode(25);

    node->left->right->left = new TreeNode(10);
    node->left->right->right = new TreeNode(14);

    vector<int> bottomView = Bottom_VIew(node);

    for(int num : bottomView){
        cout<<num<<" ";
    }
    return 0;
}