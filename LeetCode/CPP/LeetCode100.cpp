// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical,
// and the nodes have the same value.

// Look For Reference In the Book On Pg No 112


#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val = v;
        left = nullptr;
        right =nullptr;
    }
};

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p==nullptr&&q==nullptr)  return true;
    if(p==nullptr||q==nullptr)  return false;
    if(p->val!=q->val)  return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
};

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* root2 = new TreeNode(1);
    root->left = new TreeNode(2);
    root2->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root2->right = new TreeNode(3);
    cout<<boolalpha;
    cout<<"Both Tree Are Identical : "<<isSameTree(root, root2);
}