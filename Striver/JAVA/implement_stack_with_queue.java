import java.util.LinkedList;
import java.util.Queue;

public class implement_stack_with_queue {
    public static class QueueClass{
        public Queue <Integer> qt = new LinkedList<>();
        public void push(int x){
            qt.add(x);
            for(int i=0;i<qt.size()-1;i++){
                qt.add(qt.remove());
            }
        }
        public int pop(){
            if(qt.isEmpty()){
                throw new RuntimeException("Stack Is Empty");
            }
            return qt.remove();
        }
        public int top(){
            if(qt.isEmpty()){
                throw new RuntimeException("Stack Is Empty");
            }
            return qt.peek();
        }
        public boolean isQueueEmpty(){
            return qt.isEmpty();
        }
    }
    public static void main(String[] args) {
        QueueClass stack = new QueueClass();
        stack.push(4);
        stack.push(9);
        stack.push(5);
        stack.push(2);
        System.out.println("The top of the stack is " + stack.top());
        stack.pop();
        stack.pop();
        System.out.println("The top of the stack is " + stack.top());
        stack.push(1);
        stack.top();
    }
}
