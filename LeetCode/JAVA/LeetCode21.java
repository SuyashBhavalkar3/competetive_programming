// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list.
// The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Look For Reference In the Book On Pg No 58-59


public class LeetCode21 {
    public static class Node{
        int val;
        Node next;
        Node(int v){
            val = v;
            next = null;
        }
    }
    public static Node mergeTwoLinkedLists(Node head1, Node head2){
        if(head1==null)     return head2;
        if(head2==null)     return head1;
        if(head1.val<head2.val){
            head1.next = (mergeTwoLinkedLists(head1.next, head2));
            return head1;
        }
        else{
            head2.next = (mergeTwoLinkedLists(head1, head2.next));
            return head2;
        }
    }
    public static void main(String[] args) {
        Node linkedList = new Node(1);
        Node linkedList2 = new Node(1);
        linkedList.next = new Node(2);
        linkedList.next.next = new Node(4);
        linkedList2.next = new Node(3);
        linkedList2.next.next = new Node(4);
        Node temp = mergeTwoLinkedLists(linkedList, linkedList2);
        System.out.print("[");
        while(temp!=null){
            System.out.print(temp.val);
            temp = temp.next;
            if(temp!=null){
                System.out.print(", ");
            }
        }
        System.out.print("]");
    }
}
