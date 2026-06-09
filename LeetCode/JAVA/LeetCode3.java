// Given a string s, find the length of the longest substring without duplicate characters.

// Look For Reference In the Book-2 On Pg No 137-138


import java.util.HashMap;

public class LeetCode3 {
    public static int longest_substring(String s){
        char[] charArray = s.toCharArray();
        int l = 0, r = 0, n = charArray.length;
        HashMap<Character, Integer> map = new HashMap<>();
        int maxlen = 0;
        while(r<n){
            if(map.containsKey(charArray[r])){
                if(map.get(charArray[r])>=l){
                    l = map.get(charArray[r])+1;
                }
            }
            map.put(charArray[r], r);
            maxlen = Math.max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
    public static void main(String[] args) {
        String s = "pwwkew";
        System.out.println("The Longest Substring Without Repeating Characters Is : " + longest_substring(s));
        return;
    }
}