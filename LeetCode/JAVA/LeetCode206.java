public class LeetCode206 {

    public static class Node{
        int data;
        Node next;
        Node(int d){
            data = d;
            next = null;
        }
    }

    public static Node head;

    public static Node reverseLL(Node head){
        Node prev = null;
        Node curr = head;
        Node nextNode;
        while(curr!=null){
            nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    public static void main(String[] args) {
        Node newhead = new Node(1);
        newhead.next = new Node(2);
        newhead.next.next = new Node(3);
        newhead.next.next.next = new Node(4);
        newhead.next.next.next.next = new Node(5);

        Node res = reverseLL(newhead);

        System.out.print("[");
        while(res!=null){
            System.out.print(res.data);
            res=res.next;
            if(res!=null)
            System.out.print(", ");
        }
        System.out.print("]");
    }

}
