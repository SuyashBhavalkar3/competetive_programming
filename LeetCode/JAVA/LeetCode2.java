// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Look For Reference In the Book-2 On Pg No 148-149


public class LeetCode2 {
    public static class ListNode{
        ListNode next;
        int val;
        ListNode(int v){
            val = v;
            next = null;
        }
    } 
    public static ListNode add_two_number_in_linkedList(ListNode list1, ListNode list2){
        ListNode res = new ListNode(-1);
        ListNode dummy = res;
        int carry = 0;
        while(list1!=null||list2!=null||carry!=0){
            int sum = 0;
            if(list1!=null){
                sum+=list1.val;
                list1 = list1.next;
            }
            if(list2!=null){
                sum+=list2.val;
                list2 = list2.next;
            }
            sum+=carry;
            carry = sum/10;
            ListNode node = new ListNode(sum%10);
            dummy.next = node;
            dummy = dummy.next;
        }
        return res.next;
    }
    public static void main(String[] args) {
        ListNode list1Head = new ListNode(2);
        list1Head.next = new ListNode(4);
        list1Head.next.next = new ListNode(3);
        ListNode list2Head = new ListNode(5);
        list2Head.next = new ListNode(6);
        list2Head.next.next = new ListNode(4);
        ListNode res = add_two_number_in_linkedList(list1Head, list2Head);
        System.out.println("List1 : ");
        while(list1Head!=null){
            System.out.print(list1Head.val+" ");
            list1Head = list1Head.next;
        }
        System.out.println();
        System.out.println("List2 : ");
        while(list2Head!=null){
            System.out.print(list2Head.val+" ");
            list2Head = list2Head.next;
        }
        System.out.println();
        System.out.println("LinkedList After Adding");
        while(res!=null){
            System.out.print(res.val+" ");
            res = res.next;
        }
    }
}
