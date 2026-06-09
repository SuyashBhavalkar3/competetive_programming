// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Look For Reference In the Book On Pg No 53-54


public class LeetCode144{
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

    public static void preorder_traversal(TreeNode root){
        if(root == null)    return;
        System.out.print(root.val);
        if(root.left!=null){
            System.out.print(", ");
        }
        preorder_traversal(root.left);
        if(root.right!=null){
            System.out.print(", ");
        }
        preorder_traversal(root.right);
    }

    public static void main(String[] args) {
        TreeNode head = new TreeNode(1);
        head.right = new TreeNode(2);
        head.right.left = new TreeNode(3);
        System.out.print("[");
        preorder_traversal(head);
        System.out.print("]");
    }
}