// Implement a first in first out (FIFO) queue using only two stacks.
// The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.

// Look For Reference In the Book On Pg No 36-37-38


import java.util.Stack;

class MyQueue{
    private final Stack<Integer> st;

    public MyQueue() {
        st = new Stack<>();
    }

    public void push(int x){
        if (st.empty()){
            st.push(x);
        }
        else{
            int temp = st.pop();
            push(x);
            st.push(temp);
        }
    }

    public int pop(){
        return st.pop();
    }

    public int top(){
        return st.peek();
    }

    public boolean isEmpty(){
        return st.empty();
    }

    public void printQueue(){
        System.out.println(st);
    }
    
}

public class LeetCode232{
    public static void main(String[] args) {
        MyQueue queObj = new MyQueue();
        queObj.push(1);
        queObj.push(2);
        queObj.printQueue();
        System.out.println(queObj.top());
        System.out.println(queObj.pop());
        System.out.println(queObj.isEmpty());
    }
}