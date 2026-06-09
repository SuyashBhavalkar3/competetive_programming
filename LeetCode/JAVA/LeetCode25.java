// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list.
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// Look For Reference In the Book-3 On Pg No 6-7


public class LeetCode25 {
    public static class ListNode{
        int val;
        ListNode next;
        ListNode(int v){
            val = v;
            next = null;
        }
    }
    public static ListNode findKthNode(ListNode head, int k){
        k--;
        while(head!=null && k>0){
            head = head.next;
            k--;
        }
        return head;
    }
    public static void reversedLinkedList(ListNode head){
        ListNode prev = null;
        while(head!=null){
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
    }
    public static ListNode reverLinkedListInK(ListNode head, int k){
        ListNode temp = head;
        ListNode prevNode = null;
        while(temp!=null){
            ListNode KthNode = findKthNode(temp, k);
            if(KthNode==null){
                if(prevNode!=null){
                    prevNode.next = temp;
                }
                break;
            }
            ListNode nextNode = KthNode.next;
            KthNode.next = null;
            reversedLinkedList(temp);
            if(temp==head){
                head = KthNode;
            }
            else{
                prevNode.next = KthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next = new ListNode(6);
        head.next.next.next.next.next.next = new ListNode(7);
        head.next.next.next.next.next.next.next = new ListNode(8);
        head.next.next.next.next.next.next.next.next = new ListNode(9);
        head.next.next.next.next.next.next.next.next.next = new ListNode(10);
        ListNode res = reverLinkedListInK(head, 3);
        ListNode temp = res;
        while(temp!=null){
            System.out.print(temp.val+" ");
            temp = temp.next;
        }
    }
}