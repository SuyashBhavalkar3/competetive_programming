// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Look For Reference In the Book-2 On Pg No 150 - 151


public class LeetCode19{
    public static class ListNode{
        ListNode next;
        int val;
        ListNode(int v){
            val = v;
            next = null;
        }
    }
    public static ListNode remove_nth_from_rear(ListNode head, int n){
        ListNode fast = head;
        for(int i=0;i<n;i++){
            fast = fast.next;
        }
        if(fast==null)  return head.next;
        ListNode slow = head;
        while(fast.next!=null){
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return head;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        System.out.println("Linked List Before : ");
        ListNode temp1 = head;
        while(temp1!=null){
            System.out.print(temp1.val+" ");
            temp1 = temp1.next;
        }
        System.out.println("\nLinked List After Removing Nth element from rear : ");
        ListNode result = remove_nth_from_rear(head, 2);
        ListNode temp = result;
        while(temp!=null){
            System.out.print(temp.val+" ");
            temp = temp.next;
        }
    }
}