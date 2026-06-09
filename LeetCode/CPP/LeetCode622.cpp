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


#include<iostream>
#include<vector>

using namespace std;

class circular_queue{
    public:
        int f, r;
        int size;
        int capacity;
        vector<int> queue;
        circular_queue(int limit){
            f = 0;
            r = -1;
            size = 0;
            capacity = limit;
            queue.resize(capacity);
        };
        bool enqueue(int data){
            if(size==capacity){
                return false;
            }
            r = (r+1)%capacity;
            queue[r] = data;
            size++;
            return true;
        }
        bool dequeue(){
            if(size==0){
                return false;
            }
            f = (f+1)%capacity;
            size--;
            return true;
        }
        int front(){
            if(size==0){
                return -1;
            }
            return queue[f];
        }
        int rear(){
            if(size==0){
                return -1;
            }
            return queue[r];
        }
        bool isEmpty(){
            return size==0;
        }
        bool isFull(){
            return size==capacity;
        }
};

int main(){
    circular_queue cq(3);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cout<<cq.enqueue(4)<<endl; // -1
    cout<<cq.rear()<<endl;      // 3
    cout<<cq.isFull()<<endl;    // 1
    cq.dequeue();
    cq.enqueue(4);
    cout<<cq.rear()<<endl;      // 4
    return 0;
}