// You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer.
// This child pointer may or may not point to a separate doubly linked list, also containing these special nodes.
// These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

// Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list.
// Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

// Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.


// Look For Reference In the Book-2 On Pg No 22-23



public class LeetCode430{
    public static class ListNode{
        int val;
        ListNode next;
        ListNode child;
        ListNode(int v){
            val = v;
            next = null;
            child = null;
        }
    }
    public static ListNode flattenLL(ListNode head){
        if(head==null){
            return null;
        }
        ListNode curr = head;
        while(curr!=null){
            if(curr.child!=null){
                ListNode next_ = curr.next;
                curr.next = flattenLL(curr.child);
                curr.child = null;
                while(curr.next!=null){
                    curr = curr.next;
                }
                if(next_!=null){
                    curr.next = next_;
                }
            }
            curr = curr.next;
        }
        return head;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.child = new ListNode(7);
        head.next.next.child.next = new ListNode(8);
        head.next.next.child.next.child = new ListNode(11);
        head.next.next.child.next.child.next = new ListNode(12);
        head.next.next.child.next.next = new ListNode(9);
        head.next.next.child.next.next.next = new ListNode(10);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(6);
        ListNode res = flattenLL(head);
        ListNode temp = res;
        while(temp!=null){
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
    }
}