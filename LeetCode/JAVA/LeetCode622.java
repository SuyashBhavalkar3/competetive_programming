// Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

// One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

// Implement the MyCircularQueue class:

// MyCircularQueue(k) Initializes the object with the size of the queue to be k.
// int Front() Gets the front item from the queue. If the queue is empty, return -1.
// int Rear() Gets the last item from the queue. If the queue is empty, return -1.
// boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
// boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
// boolean isEmpty() Checks whether the circular queue is empty or not.
// boolean isFull() Checks whether the circular queue is full or not.
// You must solve the problem without using the built-in queue data structure in your programming language.

// Look For Reference In the Book-2 Pg No 66-67

import java.util.Scanner;

public class LeetCode622{
    public class circular_queue{
        int[] queue;
        int f, r;
        int limit;
        int size;
        circular_queue(int capacity){
            limit = capacity;
            queue = new int[limit];
            f = 0;
            r = -1;
            size = 0;
        }
        public boolean enqueue(int data){
            if(size==limit){
                return false;
            }
            r = (r+1)%limit;
            queue[r] = data;
            size++;
            return true;
        }
        public boolean dequeue(){
            if(size==0){
                return false;
            }
            f = (f+1)%limit;
            size--;
            return true;
        }
        public int front(){
            if(size==0){
                return -1;
            }
            return queue[f];
        }
        public int rear(){
            if(size==0){
                return -1;
            }
            return queue[r];
        }
        public boolean isEmpty(){
            return size==0;
        }
        public boolean isFull(){
            return size==limit;
        }
    }
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter Capacity Of Circular Queue : ");
            int capacity = sc.nextInt();
            circular_queue cq = new LeetCode622().new circular_queue(capacity);
            System.out.println("Enqueue 10 : "+cq.enqueue(10));
            System.out.println("Enqueue 20 : "+cq.enqueue(20));
            System.out.println("Front Element : "+cq.front());
            System.out.println("Rear Element : "+cq.rear());
            System.out.println("Dequeue Element : "+cq.dequeue());
            System.out.println("Front Element : "+cq.front());
            System.out.println("Is Queue Empty : "+cq.isEmpty());
            System.out.println("Is Queue Full : "+cq.isFull());
        }
    }
}