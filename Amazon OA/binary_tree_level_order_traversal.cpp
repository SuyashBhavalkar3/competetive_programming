#include <cstddef>
#include <iostream>
#include <queue>
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

vector<vector<int>> Level_Order_Traversal(TreeNode* root){
    if(root == nullptr){
        return {{}};
    }
    vector<vector<int>> ans;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode* ele = que.front();
            que.pop();
            if(ele->left!=nullptr){
                que.push(ele->left);
            }
            if(ele->right!=nullptr){
                que.push(ele->right);
            }
            level.push_back(ele->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){
    TreeNode* node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);
    vector<vector<int>> level_order_traversal = Level_Order_Traversal(node);
    cout<<"{";
    for(auto& level : level_order_traversal){
        cout<<"{";
        for(int num : level){
            cout<<num<<" ";
        }
        cout<<"} ";
    }
    cout<<"}"<<endl;
}