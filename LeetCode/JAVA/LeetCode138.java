// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
// Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// look For Reference In the Book-3 On Pg No 10-11


public class LeetCode138{
    public static class Node{
        int val;
        Node next;
        Node random;
        Node(int v){
            val = v;
            next = null;
            random = null;
        }
    }
    public static void insertCopyBetween(Node head){
        Node temp = head;
        while(temp!=null){
            Node nextNode = temp.next;
            Node copyNode = new Node(temp.val);
            copyNode.next = nextNode;
            temp.next = copyNode;
            temp = nextNode;
        }
    }
    public static void connectRandomPointers(Node head){
        Node temp = head;
        while(temp!=null){
            Node copy = temp.next;
            if(temp.random!=null){
                copy.random = temp.random.next;
            }
            temp = temp.next.next;
        }
    }
    public static Node getDeepCopy(Node head){
        Node temp  = head;
        Node dummy = new Node(-1);
        Node copyTail = dummy;
        while(temp!=null){
            Node copy = temp.next;
            copyTail.next = copy;
            copyTail = copy;
            temp.next = copy.next;
            temp = temp.next;
        }
        return dummy.next;
    }
    public static Node cloneLL(Node head){
        insertCopyBetween(head);
        connectRandomPointers(head);
        return getDeepCopy(head);
    }    
    public static void main(String[] args) {
        Node n1 = new Node(7);
        Node n2 = new Node(13);
        Node n3 = new Node(11);
        Node n4 = new Node(10);
        Node n5 = new Node(1);

        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;

        n1.random = null;
        n2.random = n1;
        n3.random = n5;
        n4.random = n3;
        n5.random = n1;

        Node newT = cloneLL(n1);
        while (newT != null) {
            System.out.println(
                "Node " + newT.val +
                " Random " + (newT.random != null ? newT.random.val : "null")
            );
            newT = newT.next;
        }
    }

}