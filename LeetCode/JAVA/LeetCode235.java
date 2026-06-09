// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in
// T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Look For Reference In the Book On Pg No 110



public class LeetCode235{
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
    public static TreeNode find_lca(TreeNode root, TreeNode p, TreeNode q){
        if(root == null)    return null;
        if(p.val<root.val && q.val<root.val){
            return find_lca(root.left, p, q);
        }
        if(p.val>root.val && q.val>root.val){
            return find_lca(root.right, p, q);
        }
        return root;
    }
    public static void main(String[] args) {
        TreeNode head = new TreeNode(4);
        head.left = new TreeNode(2);
        head.right = new TreeNode(6);
        TreeNode p = head.left;
        TreeNode q = head.right;
        System.out.println("LCA Is : " + find_lca(head, p, q).val);
    }
}