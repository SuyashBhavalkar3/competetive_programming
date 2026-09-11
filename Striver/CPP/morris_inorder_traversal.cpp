#include<iostream>
#include<vector>

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

vector<int> morrisInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{
            TreeNode* prev = curr->left;
            while(prev->right!=nullptr && prev->right!=curr){
                prev = prev->right;
            }
            if(prev->right==nullptr){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

int main(){
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->left->right->right = new TreeNode(6);
    head->right = new TreeNode(3);
    vector<int> res = morrisInorder(head);
    for(int num : res){
        cout<<num<<" ";
    }
    return 0;
}