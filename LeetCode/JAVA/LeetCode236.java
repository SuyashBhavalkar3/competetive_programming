// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
// p and q as the lowest node in T that has both p and q as descendants
// (where we allow a node to be a descendant of itself).”


// Look For Reference In the Book On Pg No 112



public class LeetCode236{
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
    public static TreeNode find_lcm(TreeNode head, TreeNode p, TreeNode q){
        if(head == null || head == p || head == q)  return head;
        TreeNode left = find_lcm(head.left, p, q);
        TreeNode right = find_lcm(head.right, p, q);
        if(left!=null && right!=null)   return head;
        return (left!=null) ? left : right;
    }
    public static void main(String[] args){
        TreeNode head = new TreeNode(4);
        head.left = new TreeNode(2);
        head.right = new TreeNode(7);
        TreeNode lcm = find_lcm(head,head.left, head.right);
        System.out.println("The Lowest Common Ancestor Of Nodes " + head.left.val + " And " + head.right.val + " Is : " + lcm.val);
    }
}