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

vector<vector<int>> ZigZag_Traversal(TreeNode* root){
    if(root == nullptr){
        return {{}};
    }
    vector<vector<int>> answer;
    queue<TreeNode*> que;
    que.push(root);
    bool leftToRight = true;
    while(!que.empty()){
        int size = que.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            TreeNode* ele = que.front();
            que.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = ele->val;
            if(ele->left!=nullptr){
                que.push(ele->left);
            }
            if(ele->right!=nullptr){
                que.push(ele->right);
            }
        }
        leftToRight = !leftToRight;
        answer.push_back(ans);
    }
    return answer;
}

int main(){
    TreeNode* node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);
    vector<vector<int>> level_order_traversal = ZigZag_Traversal(node);
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