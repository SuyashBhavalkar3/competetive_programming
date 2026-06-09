// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// Look For Reference In the Book-2 On Pg No 11


public class LeetCode141 {
    public static class ListNode{
        ListNode next;
        ListNode(int v){
            next = null;
        }
    }
    public static boolean hasCycle(ListNode head){
        if(head == null|| head.next == null)    return false;
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null&&fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast)  return true;
        }
        return false;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = head.next;
        System.out.println("Linked Has Cycle : " + hasCycle(head));
    }
}
