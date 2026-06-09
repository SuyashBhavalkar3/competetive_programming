// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Look For Reference In the Book On Pg No 87

public class LeetCode98{
    public static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int v){
            val = v;
            left = null;
            right = null;
        }
    }
    static TreeNode prev = null;
    public static boolean helper(TreeNode root){
        if(root == null)    return true;
        if(!helper(root.left))  return false;
        if(prev!=null && prev.val>=root.val)    return false;
        prev = root;
        return helper(root.right);
    }
    public static boolean isValid(TreeNode root){
        return helper(root);
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);
        System.out.println("The Tree Is Valid BST : " + isValid(root));
    }
}