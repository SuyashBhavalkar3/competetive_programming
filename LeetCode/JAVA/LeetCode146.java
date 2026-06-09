// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.


// Look For Reference In the Book-2 On Pg No 58-59


import java.util.HashMap;
import java.util.Scanner;

public class LeetCode146{
    public class Node{
        int key, value;
        Node next;
        Node prev;
        Node(int k, int v){
            key = k;
            value = v;
            next = null;
            prev = null;
        }
    }
    public class LRUCache{

        int limit;
        HashMap<Integer, Node> map = new HashMap<>();
        Node head = new Node(-1, -1);
        Node tail = new Node(-1, -1);

        public LRUCache(int capacity) {
            head.next = tail;
            tail.prev = head;
            limit = capacity;
        }

        public void addNode(Node NodeToAdd){
            Node oldNext = head.next;
            head.next = NodeToAdd;
            oldNext.prev = NodeToAdd;
            NodeToAdd.prev = head;
            NodeToAdd.next = oldNext;
        }

        public void deleteNode(Node NodeToDel){
            Node prevOfdel = NodeToDel.prev;
            Node nextOfdel = NodeToDel.next;
            prevOfdel.next = nextOfdel;
            nextOfdel.prev = prevOfdel;
        }

        public int get(int key){
            if(!map.containsKey(key)){
                return -1;
            }
            Node node_ = map.get(key);
            int ans = node_.value;
            deleteNode(node_);
            addNode(node_);
            return ans;
        }

        public void put(int key, int value){
            if(limit==0) return;
            if(map.containsKey(key)){
                Node existing = map.get(key);
                deleteNode(existing);
                map.remove(key);
            }
            if(map.size()==limit){
                Node lru = tail.prev;
                map.remove(lru.key);
                deleteNode(lru);
            }
            Node newNode = new Node(key, value);
            addNode(newNode);
            map.put(key, newNode);
        }
    }

    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter Capacity Of LRU Cache");
            int cap = sc.nextInt();
            LRUCache lruObj = new LeetCode146().new LRUCache(cap);
            lruObj.put(1, 1);
            lruObj.put(2, 2);
            System.out.println(lruObj.get(1));
            lruObj.put(3, 3);
            System.out.println(lruObj.get(2));
            lruObj.put(4, 4);
            System.out.println(lruObj.get(1));
            System.out.println(lruObj.get(3));
            System.out.println(lruObj.get(4));
        }
    }
}