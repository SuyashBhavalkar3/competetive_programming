#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
   Custom iterator class that can traverse the tree from smallest to largest
   or from largest to smallest, depending on the initialization flag
*/
class BSTIterator {
private:
    stack<TreeNode*> st;
    // true = descending, false = ascending
    bool reverse; 
    
    // Helper function to push all boundary nodes onto the stack
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            // If traversing backwards, load right children. Otherwise, load left children.
            if (reverse == true) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    // Constructor initializes the appropriate path
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    // Retrieves the next target element in the sequence
    int next() {
        TreeNode* topNode = st.top();
        st.pop();
        
        // If traversing backwards, look left for the next smaller element
        if (reverse == true) {
            pushAll(topNode->left);
        } 
        // If traversing forwards, look right for the next larger element
        else {
            pushAll(topNode->right);
        }
        
        return topNode->val;
    }
};

class Solution {
public:
    /*
       Main function linking the forward and reverse iterators
       to simulate the optimal two-pointer array technique
    */
    bool findTarget(TreeNode* root, int k) {
        // Guard clause for empty trees
        if (root == nullptr) return false;
        
        // Initialize one iterator at the minimum and one at the maximum
        BSTIterator leftIter(root, false);
        BSTIterator rightIter(root, true);
        
        int i = leftIter.next();
        int j = rightIter.next();
        
        // Loop until the iterators cross each other
        while (i < j) {
            int currentSum = i + j;
            
            // The exact sum is found
            if (currentSum == k) {
                return true;
            }
            
            // Sum is too small, advance the left iterator
            if (currentSum < k) {
                i = leftIter.next();
            } 
            // Sum is too large, advance the right iterator
            else {
                j = rightIter.next();
            }
        }
        
        return false;
    }
};

// Driver code starts here
int main() {
    // Construct the sample tree: [5, 3, 6, 2, 4, null, 7]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    Solution obj;
    int k = 9;
    
    // Check if the target exists
    bool result = obj.findTarget(root, k);
    cout << (result ? "true" : "false") << endl;
    
    return 0;
}