// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// Look For Reference In the Book On Pg No 149



import java.util.Scanner;

public class LeetCode567{
    public static boolean isSameArray(int[] freq, int[] windowFreq){
        for(int i=0;i<26;i++){
            if(freq[i]!=windowFreq[i])  return false;
        }
        return true;
    }
    public static boolean permutationInStrings(String s1, String s2){
        int[] freq = new int[26];
        for(char ch : s1.toCharArray()){
            freq[ch-'a']++;
        }
        int windowSize = s1.length();
        char[] arr = s2.toCharArray();
        for(int i=0;i<s2.length();i++){
            int idx = i, windowIdx = 0;
            int[] windowFreq = new int[26];
            while(windowIdx<windowSize && idx<s2.length()){
                windowFreq[arr[idx]-'a']++;
                idx++;
                windowIdx++;
            }
            if(isSameArray(freq, windowFreq))   return true;
        }
        return false;
    }
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            String s1 = sc.next();
            String s2 = "eidbaooo";
            System.out.println(permutationInStrings(s1, s2));
        }
    }
}