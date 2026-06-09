// Given the root of a binary search tree, and an integer k,
// return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Look For Reference In the Book On Pg No 88-89

public class LeetCode230{

    static int result;
    static int cnt = 1;
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
    public static void inorderHelper(TreeNode root, int k){
        if(root==null)  return;
        inorderHelper(root.left, k);
        if(cnt==k){
            result = root.val;
            return;
        }
        cnt++;
        inorderHelper(root.right, k);
    }
    public static int KthSmallest(TreeNode root, int k){
        inorderHelper(root, k);
        return result;
    }
    public static void main(String[] args) {
        TreeNode head = new TreeNode(6);
        head.left = new TreeNode(1);
        head.right = new TreeNode(8);
        head.left.right = new TreeNode(2);
        int k=3;
        System.out.println("The " + k + "th " + "Smallest Element Is : " + KthSmallest(head, k));
    }
}