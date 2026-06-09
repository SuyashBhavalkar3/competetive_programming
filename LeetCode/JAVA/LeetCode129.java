// You are given the root of a binary tree containing digits from 0 to 9 only.
// Each root-to-leaf path in the tree represents a number.
// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
// A leaf node is a node with no children.

// Look For Reference In the Book-2 On Pg No 90-91


public class LeetCode129{
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
    public static void dfs(TreeNode head, int currSum){
        if(head==null)  return;
        currSum = (currSum*10)+head.val;
        if(head.left==null && head.right==null){
            sum+=currSum;
            return;
        }
        dfs(head.left,currSum);
        dfs(head.right,currSum);
    }
    public static int SLTR(TreeNode head){
        if(head==null)  return 0;
        sum = 0;
        int currSum = 0;
        dfs(head,currSum);
        return sum;
    }
    public static void main(String[] args){
        TreeNode head = new TreeNode(1);
        head.right = new TreeNode(2);
        head.left = new TreeNode(3);
        System.out.println("Sum of Root To Leaf Numbers : " + SLTR(head));
    }
}