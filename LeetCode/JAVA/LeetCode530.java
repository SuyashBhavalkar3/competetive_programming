// Given the root of a Binary Search Tree (BST),
// return the minimum absolute difference between the values of any two different nodes in the tree.

// Look For Reference In the Book On Pg No 65-66

public class LeetCode530{
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
    static Integer prev = null;
    static int minDiff = Integer.MAX_VALUE;
    public static void inorder(TreeNode root){
        if (root == null)   return;
        inorder(root.left);
        if(prev!=null){
            minDiff = Math.min(minDiff, root.val - prev);
        }
        prev = root.val;
        inorder(root.right);
    }
    public static int findMinDifference(TreeNode root){
        inorder(root);
        return minDiff;
    }
    public static void main(String[] args){
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right = new TreeNode(6);
        System.out.println("The Minimum Absolute Distance Between Nodes Are : "+findMinDifference(root));
    }
}