// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

// Look For Reference In the Book On Pg No 41-42


public class LeetCode876{

    public static class ListNode{
        int val;
        ListNode next;
        ListNode(int v){
            val = v;
            next = null;
        }
    }

    public static ListNode findMiddle(ListNode head){
        ListNode slow = head;
        ListNode fast = head;
        while (fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(6);

        ListNode res = findMiddle(head);
        System.out.print("[");
        while(res!=null){
            System.out.print(res.val);
            res = res.next;
            if(res!=null){
                System.out.print(", ");
            }
        }
        System.out.print("]");
    }

}