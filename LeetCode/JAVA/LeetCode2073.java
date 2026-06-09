// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

// You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

// Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets.
// If a person does not have any tickets left to buy, the person will leave the line.

// Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

// Look For Reference In the Book On Pg No 96-97


import java.util.LinkedList;
import java.util.Queue;

public class LeetCode2073{
    public static int timeRequired(int[] arr, int k){
        int timeRequired=0;
        Queue<Integer> que = new LinkedList<>();
        for(int i=0;i<arr.length;i++){
            que.offer(i);
        }
        while (true) {
            int index = que.poll();
            timeRequired++;
            arr[index]--;
            if(index==k && arr[index]==0)   break;
            if(arr[index]>0){
                que.offer(index);
            }
        }
        return timeRequired;
    }
    public static void main(String[] args){
        int[] arr = {2,3,2};
        int k = 2;
        System.out.println("Time Required In Queue Is : " + timeRequired(arr, k));
    }
}