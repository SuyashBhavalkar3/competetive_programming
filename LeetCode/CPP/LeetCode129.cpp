// You are given the root of a binary tree containing digits from 0 to 9 only.
// Each root-to-leaf path in the tree represents a number.
// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
// A leaf node is a node with no children.

// Look For Reference In the Book-2 On Pg No 90-91


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

int dfs(TreeNode* head, int currSum){
    if(head==nullptr)   return 0;
    currSum = currSum*10 + head->val;
    if(head->left==nullptr && head->right==nullptr){
        cout<<"Root-to-leaf path sum: "<<currSum<<endl;
        return currSum;
    }
    return dfs(head->left, currSum) + dfs(head->right, currSum);
}

int SRTL(TreeNode* head){
    if(head==nullptr)   return 0;
    int currSum = 0;
    return dfs(head, currSum);
}

int main(){
    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(9);
    head->right = new TreeNode(0);
    head->left->left = new TreeNode(5);
    head->left->right = new TreeNode(1);
    cout<<"Sum of all root-to-leaf paths: "<<SRTL(head)<<endl;
    return 0;
}