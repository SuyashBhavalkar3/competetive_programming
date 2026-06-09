// Given the head of a linked list, rotate the list to the right by k places.

// Look For Reference In the Book-3 On Pg No 8-9


public class LeetCode61 {
    public static class ListNode{
        ListNode next;
        int val;
        ListNode(int v){
            val = v;
            next = null;
        }
    }

    public static ListNode rotateList(ListNode head, int k){
        if(head==null||head.next==null||k==0){
            return head;
        }
        int length = 1;
        ListNode temp = head;
        while(temp.next!=null){
            temp = temp.next;
            length++;
        }
        temp.next = head;
        k = k%length;
        if(k==0){
            temp.next = null;
            return head;
        }
        int StepsToK = length-k;
        ListNode newTemp = head;
        for(int i=1;i<StepsToK;i++){
            newTemp = newTemp.next;
        }
        ListNode newHead = newTemp.next;
        newTemp.next = null;
        return newHead;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        ListNode tempN = head;
        while(tempN!=null){
            System.out.print(tempN.val+" ");
            tempN = tempN.next;
        }
        System.out.println();
        ListNode res = rotateList(head, 2);
        ListNode temp = res;
        while(temp!=null){
            System.out.print(temp.val+" ");
            temp = temp.next;
        }
    }
}
