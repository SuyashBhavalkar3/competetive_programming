// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Look For Reference In the Book On Pg No 42-43


import java.util.ArrayList;
import java.util.List;

public class LeetCode94{

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

    public static void inorderHelper(TreeNode head, List<Integer> result){
        if(head == null)    return;
        inorderHelper(head.left, result);
        result.add(head.val);
        inorderHelper(head.right, result);
    }

    public static List<Integer> inorder(TreeNode head){
        List<Integer> res = new ArrayList<>();
        inorderHelper(head, res);
        return res;
    }

    public static void main(String[] args) {
        TreeNode head = new TreeNode(2);
        head.left = new TreeNode(1);
        head.right = new TreeNode(3);
        List<Integer> res = inorder(head);
        System.out.println(res);
    }

}