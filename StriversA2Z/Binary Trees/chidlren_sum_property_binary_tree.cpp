#include <ios>
#include <iostream>
#include <ostream>
#include <queue>

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

bool Property_Child_Sum(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    cout<<"Pushed : "<<root->val<<endl;
    while(!que.empty()){
        TreeNode* ele = que.front();
        cout<<"Ele : "<<ele->val<<endl; 
        int sum_needed = ele->val;
        int leftVal = ele->left == nullptr ? 0 : ele->left->val;
        int rightVal = ele->right == nullptr ? 0 : ele->right->val;
        if(ele->left!=nullptr || ele->right!=nullptr){
            if(leftVal+rightVal!=sum_needed){
                cout<<"Sum needed : "<<sum_needed<<endl;
                cout<<"leftVal : "<<leftVal<<endl;
                cout<<"rightVal : "<<rightVal<<endl;
                return false;
            }
        }
        que.pop();
        if(ele->left!=nullptr){
            que.push(ele->left);
        }
        if(ele->right!=nullptr){
            que.push(ele->right);
        }
    }
    return true;
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    bool property_applies = Property_Child_Sum(root);
    cout<<"The Children Sum Property On Given Binary Tree Applies ? : "<<boolalpha<<property_applies<<endl;
    return 0;
}