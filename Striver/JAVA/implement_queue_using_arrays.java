class Queue{
    int start, end, currSize, size;
    int[] queue;
    Queue(int s){
        size = s;
        start = -1;
        end = -1;
        currSize = 0;
        queue = new int[size];
    }
    public void push(int val){
        if(currSize == size){
            System.out.println("Can't Push To Queue, Queue Overflow!");
            return;
        }
        if(currSize == 0){
            start = 0;
            end = 0;
        }
        else{
            end = (end+1)%size;
        }
        currSize++;
        queue[end] = val;
    }
    void pop(){
        if(currSize==0){
            System.out.println("Cant Pop, Queue Underflow!");
            return;
        }
        currSize--;
        if(currSize == 0){
            start = -1;
            end = -1;
        }
        else{
            start = (start+1)%size;
        }
    }
    int top(){
        if(currSize==0){
            System.out.println("Queue Is Empty!");
            return -1;
        }
        return queue[start];
    }
    boolean isEmpty(){
        return currSize == 0;
    }
}
public class implement_queue_using_arrays {
    public static void main(String[] args) {
        Queue qu = new Queue(5);
        qu.push(10);
        qu.push(20);
        qu.push(30);
        System.out.println("The top of the Queue is : " + qu.top());
        qu.pop();
        System.out.println("The top of the Queue is : " + qu.top());
        qu.push(40);
        qu.push(50);
        qu.push(60);
        System.out.println("The Queue is empty : " + qu.isEmpty());
        qu.push(70);
        System.out.print("The Queue is : ");
       while(!qu.isEmpty()){
            System.out.print(qu.top() + " ");
            qu.pop();
        }
    }
}
