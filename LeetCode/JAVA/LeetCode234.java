// Given the head of a singly linked list, return true if it is a palindrome or false otherwise->
// Look For Reference In the Book On Pg No 82-83


public class LeetCode234{
    public static class ListNode{
        int val;
        ListNode next;
        ListNode(int v){
            val = v;
            next = null;
        }
    }
    public static ListNode reverse(ListNode head){
        ListNode prev = null;
        ListNode nextnode;
        ListNode curr = head;
        while(curr!=null){
            nextnode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    public static boolean isPalindrome(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode secondHalf = reverse(slow);
        ListNode firstHalf = head;
        while(secondHalf!=null){
            if(firstHalf.val!=secondHalf.val){
                return false;
            }
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }
        return true;
    }
    public static void main(String[] args){
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(2);
        head.next.next.next = new ListNode(1);
        boolean res = isPalindrome(head);
        System.out.println("The Linked List Is Palindrome : " + res);
    }
}