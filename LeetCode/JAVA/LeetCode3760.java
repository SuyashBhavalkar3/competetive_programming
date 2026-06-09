// You are given a string s consisting of lowercase English letters.

// Return an integer denoting the maximum number of substrings you can split s
// into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).

// Look For Reference In the Book-2 On Pg No 2


public class LeetCode3760 {
    public static int getDistinct(String str){
        int[] distanceChar = new int[26];
        for(char ch : str.toCharArray()){
            distanceChar[ch-'a']++;
        }
        int cnt=0;
        for(int num : distanceChar){
            if(num!=0 && num>0) cnt++;
        }
        return cnt;
    }
    public static void main(String[] args) {
        String str = "abcd";
        System.out.println(getDistinct(str));
    }
}
