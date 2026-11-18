#include <cstddef>
#include <iostream>
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

bool isBoundary(TreeNode* root, int idx, int n){
    if(idx!=0 && idx!=n-1 && (root->left!=nullptr && root->right!=nullptr)){
        return false;
    }
    return true;
}

bool isLeaf(TreeNode* root){
    return root!=nullptr && root->left == nullptr && root->right == nullptr;
}

void addLeftBoundary(TreeNode* root, vector<int>& ans){
    TreeNode* curr = root->left;
    while(curr!=nullptr){
        if(!isLeaf(curr)){
            ans.push_back(curr->val);
        }
        if(curr->left!=nullptr){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
}

void addLeaves(TreeNode* root, vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back((root->val));
        return;
    }
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void addRightBoundary(TreeNode* root, vector<int>& ans){
    vector<int> temp;
    TreeNode* curr = root->right;
    while(curr!=nullptr){
        if(!isLeaf(curr)){
            temp.push_back(curr->val);
        }
        if(curr->left!=nullptr){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    int n = temp.size();
    for(int i=n-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

vector<int> Boundary_Traversal(TreeNode* root){
    vector<int> ans;
    if(root==nullptr){
        return {};
    }
    if(!isLeaf(root)){
        ans.push_back(root->val);
    }
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
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

    node->left->right->left = new TreeNode(8);
    node->left->right->right = new TreeNode(9);
    vector<int> boundary = Boundary_Traversal(node);
    cout<<"{";
    // for(auto& level : level_order_traversal){
    //     cout<<"{";
        for(int num : boundary){
            cout<<num<<" ";
        }
        // cout<<"} ";
    // }
    cout<<"}"<<endl;
}