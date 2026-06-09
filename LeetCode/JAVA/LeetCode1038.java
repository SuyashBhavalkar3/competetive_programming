// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST
// is changed to the original key plus the sum of all keys greater than the original key in BST.

// As a reminder, a binary search tree is a tree that satisfies these constraints:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Look For Reference In the Book-2 On Pg No 70


public class LeetCode1038 {
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
    public static int sum = 0;
    public static void dfs(TreeNode root){
        if(root == null){
            return;
        }
        dfs(root.right);
        sum+=root.val;
        root.val = sum;
        dfs(root.left);
    }
    public static TreeNode BstToGst(TreeNode head){
        if(head == null){
            return null;
        }
        dfs(head);
        return head;
    }
    public static void print_Tree(TreeNode root){
        if(root==null){
            return;
        }
        print_Tree(root.left);
        System.out.print(root.val+" ");
        print_Tree(root.right);
    }
    public static void main(String[] args) {
        TreeNode head = new TreeNode(4);
        head.left = new TreeNode(1);
        head.left.left = new TreeNode(0);
        head.left.right = new TreeNode(2);
        head.left.right.right = new TreeNode(3);
        head.right = new TreeNode(6);
        head.right.left = new TreeNode(5);
        head.right.right = new TreeNode(7);
        head.right.right.right = new TreeNode(8);
        TreeNode result = BstToGst(head);
        print_Tree(result);             //It Should Return Descending Order Values of the Tree ie. 36 36 35 33 30 26 21 15 8 for Given Input
    }
}