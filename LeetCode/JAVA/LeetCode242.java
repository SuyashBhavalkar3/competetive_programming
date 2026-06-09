// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Look For Reference In the Book On Pg No 47-48

import java.util.HashMap;

public class LeetCode242{

    public static boolean isAnagram(String s, String t){
        HashMap<Character, Integer> map = new HashMap<>();
        char[] scharArr = s.toCharArray();
        for (char c : scharArr){
            map.put(c, map.getOrDefault(c, 0)+1);
        }
        char[] tcharArr = t.toCharArray();
        for (char c : tcharArr){
            if(!map.containsKey(c)){
                return false;
            }
            map.put(c, map.get(c)-1);
            if(map.get(c)==0){
                map.remove(c);
            }
        }
        return map.isEmpty();
    }

    public static void main(String[] args) {
        String s = "anagram";
        String t = "nagarama";
        boolean res = isAnagram(s, t);
        System.out.println("The Strings Are Anagram : "+res);
    }
}