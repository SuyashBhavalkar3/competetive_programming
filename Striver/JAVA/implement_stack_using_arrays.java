class Stack{
    private int[] stack;
    private int top;
    private int size;
    public Stack(int s){
        size = s;
        top = -1;
        stack = new int[size];
    }
    void push(int val){
        if(top == size-1){
            System.out.println("Cannot Push , Stack Overflow!");
            return;
        }
        stack[++top] = val;
    }
    void pop(){
        if(top == -1){
            System.out.println("Cannot Pop, Stack Underflow!");
            return;
        }
        top--;
    }
    int top(){
        if(top == -1){
            System.out.println("Stack Is Empty!");
            return -1;
        }
        return stack[top];
    }
    boolean isEmpty(){
        return top == -1;
    }
}
public class implement_stack_using_arrays {
    public static void main(String[] args) {
        Stack st = new Stack(5);
        st.push(10);
        st.push(20);
        st.push(30);
        System.out.println("Top: " + st.top());
        st.pop();
        System.out.println("Top After Pop : " + st.top()); 
    }
}
