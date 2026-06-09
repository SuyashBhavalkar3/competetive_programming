// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root->

// The length of a path between two nodes is represented by the number of edges between them.

// Look For Reference In the Book On Pg No 128-129

public class LeetCode543{
    public static class TreeNode{
        TreeNode left;
        TreeNode right;

        public TreeNode(int v) {
            left = null;
            right = null;
        }
    
    }
    public static int diameter = 0;
    public static int height(TreeNode root){
        if(root==null)  return 0;
        int lh = height(root.left);
        int rh = height(root.right);
        diameter = Math.max(diameter, lh+rh);
        return 1+Math.max(lh,rh);
    }
    public static int findDiameter(TreeNode root){
        height(root);
        return diameter;
    }
    public static void main(String[] args){
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.right = new TreeNode(4);
        root.right.right = new TreeNode(5);
        System.out.println("Diameter Is  : " + findDiameter(root));
    }
}