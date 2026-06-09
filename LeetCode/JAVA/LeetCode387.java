// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Look For Reference In the Book On Pg No 73



import java.util.HashMap;


public class LeetCode387{
    public static int nonRepeating(String str){
        HashMap<Character, Integer> map = new HashMap<>();
        char[] charArray = str.toCharArray();
        for(int i=0;i<charArray.length;i++){
            map.put(charArray[i], map.getOrDefault(charArray[i], 0)+1);
        }
        for(int i=0;i<charArray.length;i++){
            if(map.get(charArray[i])==1)    return i;
        }
        return 0;
    }
    public static void main(String[] args) {
        String str = "leetcode";
        int res = nonRepeating(str);
        System.out.println("First Non Repeating Char Is At : " + res);
    }
}