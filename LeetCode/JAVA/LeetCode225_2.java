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
    private Queue<Integer> q1;
    private Queue<Integer> q2;
    public MyStack() {
            q1 = new LinkedList<>();
            q2 = new LinkedList<>();
        }
    
    public void push(int x){
        q2.offer(x);
        while(!q1.isEmpty()){
            q2.offer(q1.poll());
        }
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;

    }

    public int pop(){
        return q1.poll();
    }
    
    public int top(){
        return q1.peek();
    }

    public boolean isEmptyQueue(){
        return  q1.isEmpty();
    }

    public void printQueue(){
        System.out.println(q1);
    }

}

public class LeetCode225_2{
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
        System.out.println(stackObj.isEmptyQueue());
    }
}