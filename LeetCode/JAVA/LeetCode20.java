// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


// Look For Reference In the Book On Pg No 69-70



import java.util.HashMap;
import java.util.Stack;

public class LeetCode20{

    public static boolean isValidParenthesis(String str){
        Stack<Character> stack = new Stack<>();
        HashMap<Character, Character> map = new HashMap<>();
        map.put(')', '(');
        map.put(']', '[');
        map.put('}', '{');
        for(char c : str.toCharArray()){
            if(map.containsKey(c)){
                char topValue;
                if(stack.empty())   topValue = '#';
                else    topValue = stack.pop();
                if(topValue!=map.get(c))    return false;
            }
            else{
                stack.push(c);
            }
        }
        return stack.empty();
    }

    public static void main(String[] args) {
        String str = "({[]})";
        boolean res = isValidParenthesis(str);
        System.out.print(res);
    }
}