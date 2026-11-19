#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    // Explicit stack to simulate and pause the recursion
    stack<TreeNode*> st;
    
    // Helper function to push the current node and all its left children
    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    // Constructor initializes the state by loading the leftmost path
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    // Retrieves the next smallest element and updates the stack state
    int next() {
        // The top of the stack is always the next smallest value
        TreeNode* topNode = st.top();
        st.pop();
        
        // If the processed node has a right branch, load its leftmost path
        if (topNode->right != nullptr) {
            pushAllLeft(topNode->right);
        }
        
        return topNode->val;
    }
    
    // Returns true as long as there are pending nodes in the stack
    bool hasNext() {
        return !st.empty();
    }
};

// Driver code starts here
int main() {
    // Construct the sample tree
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    
    // Instantiate the iterator object
    BSTIterator* obj = new BSTIterator(root);
    
    // Simulate iterator calls
    cout << obj->next() << endl;    // 3
    cout << obj->next() << endl;    // 7
    cout << (obj->hasNext() ? "true" : "false") << endl; // true
    cout << obj->next() << endl;    // 9
    
    return 0;
}