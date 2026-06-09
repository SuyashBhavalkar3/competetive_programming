// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical,
// and the nodes have the same value.

// Look For Reference In the Book On Pg No 112


public class LeetCode100{
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

    public static boolean isSameTree(TreeNode p, TreeNode q){
        if(p==null&&q==null)    return true;
        if(p==null||q==null)    return false;
        if(p.val!=q.val)    return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
    public static void main(String[] args){
        TreeNode root = new TreeNode(1);
        TreeNode root2 = new TreeNode(1);
        root.left = new TreeNode(2);
        root2.left = new TreeNode(2);
        root.right = new TreeNode(4);
        root2.right = new TreeNode(4);
        System.out.println("Two Trees Are Identical  : " + "\" "+ isSameTree(root, root2) + "\" ");
    }
}