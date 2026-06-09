
import java.util.Stack;

class MyQueue{
    private final Stack<Integer> s1;
    private final Stack<Integer> s2;

    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }

    public void push(int x){
        while(!s1.isEmpty()){
            s2.push(s1.pop());
        }
        s1.push(x);
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
    }

    public int pop(){
        return s1.pop();
    }

    public int top(){
        return s1.peek();
    }

    public boolean isEmpty(){
        return s1.empty();
    }

    public void printQueue(){
        System.out.println(s1);
    }
    
}

public class LeetCode232_2{
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