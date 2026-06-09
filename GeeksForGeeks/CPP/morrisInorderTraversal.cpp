// Find Out the Morris Inorder Traversal For The Given Tree

// Look For Reference In the Book On Pg No 126-127


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
        right = nullptr;
    }
};

void morris_traversal(TreeNode* root){
    cout<<"[";
    while(root!=nullptr){
        if(root->left==nullptr){
            cout<<root->val;
            if(root->right!=nullptr)    cout<<", ";
            root = root->right;
        }
        else{
            TreeNode* predecessor = root->left;
            while(predecessor->right!=nullptr && predecessor->right!=root){
                predecessor = predecessor->right;
            }
            if(predecessor->right == nullptr){
                predecessor->right = root;
                root = root->left;
            }
            else{
                predecessor->right = nullptr;
                cout<<root->val;
                root = root->right;
                if(root!=nullptr)   cout<<", ";
            }
        }
    }
    cout<<"]";
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    morris_traversal(root);
    return 0;
}