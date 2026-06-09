// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Look For Reference In the Book On Pg No 74-75

public class LeetCode101{

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

    public static boolean checkSymmetric(TreeNode leftN, TreeNode rightN){
        if(leftN==null&&rightN==null)   return true;
        if(leftN==null||rightN==null)   return false;
        if(leftN.val!=rightN.val)   return false;
        return ((checkSymmetric(leftN.left, rightN.right)) && (checkSymmetric(leftN.right, rightN.left)));
    }

    public static boolean isSymmetric(TreeNode root){
        return checkSymmetric(root.left, root.right);
    }

    public static void main(String[] args){
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        System.out.println("Tree Is Symmetric : " + isSymmetric(root));
    }
}