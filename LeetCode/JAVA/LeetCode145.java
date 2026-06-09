// Given the root of a binary tree, return the postorder traversal of its nodes' values.

// Look For Reference In the Book On Pg No 59-60


import java.util.ArrayList;
import java.util.List;

public class LeetCode145{

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

    public static void postorderHelper(TreeNode head, List<Integer> result){
        if(head == null)    return;
        postorderHelper(head.left, result);
        postorderHelper(head.right, result);
        result.add(head.val);
    }

    public static List<Integer> postorder(TreeNode head){
        List<Integer> res = new ArrayList<>();
        postorderHelper(head, res);
        return res;
    }

    public static void main(String[] args) {
        TreeNode head = new TreeNode(2);
        head.left = new TreeNode(1);
        head.right = new TreeNode(3);
        List<Integer> res = postorder(head);
        System.out.println(res);
    }

}