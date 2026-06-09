// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.


import java.util.Stack;

public class LeetCode155 {

    static class MinStack {
        private final Stack<Integer> s;
        private int minValue;

        public MinStack() {
            s = new Stack<>();
        }

        public void push(int val) {
            if (s.isEmpty()) {
                s.push(val);
                minValue = val;
            } else if (val < minValue) {
                s.push(2 * val - minValue);
                minValue = val;
            } else {
                s.push(val);
            }
        }

        public void pop() {
            if (s.isEmpty()) return;

            int top = s.pop();
            if (top < minValue) {
                minValue = 2 * minValue - top;
            }
        }

        public int top() {
            int top = s.peek();
            if (top < minValue) {
                return minValue;
            }
            return top;
        }

        public int getMin() {
            return minValue;
        }
    }

    public static void main(String[] args) {
        MinStack ms = new MinStack();

        ms.push(0);
        ms.push(-3);

        System.out.println("Min: " + ms.getMin());
        ms.pop();
        System.out.println("Top: " + ms.top());
        System.out.println("Min: " + ms.getMin());
    }
}
