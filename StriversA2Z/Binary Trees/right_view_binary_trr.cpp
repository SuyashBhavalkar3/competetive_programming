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

vector<int> Right_View(TreeNode* root){
    if(root == nullptr){
        return {};
    }
    queue<TreeNode*> que;
    que.push(root);
    vector<int> ans;
    while(!que.empty()){
        int size = que.size();
        for(int i=0;i<size;i++){
            TreeNode* ele = que.front();
            que.pop();
            if(ele->left!=nullptr){
                que.push(ele->left);
            }
            if(ele->right!=nullptr){
                que.push(ele->right);
            }
            if(i==size-1){
                ans.push_back(ele->val);
            }
        }
    }
    return ans;
}

int main(){
    TreeNode* node = new TreeNode(1);

    node->left = new TreeNode(2);
    node->right = new TreeNode(3);

    node->left->right = new TreeNode(5);
    node->right->right = new TreeNode(4);

    vector<int> rightView = Right_View(node);

    for(int num : rightView){
        cout<<num<<" ";
    }
    return 0;
}