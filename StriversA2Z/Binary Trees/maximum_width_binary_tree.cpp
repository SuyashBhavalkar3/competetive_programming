#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>

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

int Maximum_Width_Binary_Tree(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int first = 0;
    int last = 0;
    int widthTreee = 0;
    queue<pair<TreeNode*, int>> que;
    que.push({root, 0});
    while(!que.empty()){
        int size = que.size();
        int minIdx = que.front().second;
        for(int i=0;i<size;i++){
            auto poppedNode = que.front();
            que.pop();
            int indexId = poppedNode.second - minIdx;
            if(i == 0){
                first = indexId;
            }
            if(i == size-1){
                last = indexId;
            }
            if(poppedNode.first->left!=nullptr){
                que.push({poppedNode.first->left, (indexId*2)+1});
            }
            if(poppedNode.first->right!=nullptr){
                que.push({poppedNode.first->right, (indexId*2)+2});
            }
        }
        widthTreee = max(widthTreee, last-first+1);
    }
    return widthTreee;
}


int main(){
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(3);
    head->right = new TreeNode(2);
    head->left->left = new TreeNode(5);
    head->right->right = new TreeNode(9);
    head->left->left->left = new TreeNode(6);
    head->right->right->left = new TreeNode(7);
    int maxWidth = Maximum_Width_Binary_Tree(head);
    cout<<"The Maximum Width Of Binary Tree Is : "<<maxWidth<<endl;
    return 0;
}