// Implement a last-in-first-out (LIFO) stack using only two queues.
// The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.


// Look For Reference In the Book On Pg No 31-32


import java.util.LinkedList;
import java.util.Queue;

class MyStack{
    private final Queue<Integer> queueOfInt;
    public MyStack() {
            queueOfInt = new LinkedList<>();
        }
    
    public void push(int x){
        queueOfInt.offer(x);
        int size = queueOfInt.size();
        for(int i=1;i<size;i++){
            queueOfInt.offer(queueOfInt.poll());
        }
    }

    public int pop(){
        return queueOfInt.poll();
    }
    
    public int top(){
        return queueOfInt.peek();
    }

    public boolean isEmptyQueue(){
        return  queueOfInt.isEmpty();
    }

    public void printQueue(){
        System.out.println(queueOfInt);
    }

}

public class LeetCode225{
    public static void main(String[] args) {
        MyStack stackObj = new MyStack();
        stackObj.printQueue();
        stackObj.push(1);
        System.out.println(stackObj.top());
        stackObj.push(2);
        System.out.println(stackObj.top());
        stackObj.printQueue();
        System.out.println(stackObj.pop());
        stackObj.printQueue();
    }
}