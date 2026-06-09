// Given a binary tree, determine if it is height-balanced.

// Look For Reference In the Book-2 On Pg No 12


public class LeetCode110{
    public static class TreeNode{
        TreeNode left;
        TreeNode right;
        TreeNode(int v){
            left = null;
            right = null;
        }
    }
    public static boolean has_same_height = true;
    public static int checkHeight(TreeNode root){
        if(root==null)  return 0;
        int lh = checkHeight(root.left);
        int rh = checkHeight(root.right);
        if(Math.abs(lh-rh)>1){
            has_same_height = false;
        }
        return 1+Math.max(lh, rh);
    }
    public static boolean has_same_height2(TreeNode root){
        checkHeight(root);
        return has_same_height;
    }
    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.right = new TreeNode(20);
        root.left = new TreeNode(9);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        System.out.println("Tree Has Balanced Height : " + has_same_height2(root));
    }
}