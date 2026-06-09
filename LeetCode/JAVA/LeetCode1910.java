// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.


// Look For Reference In the Book On Pg No 105-106



public class LeetCode1910{
    public static String removeOccurrences(String s, String part){
        StringBuilder strbld = new StringBuilder();
        for(char ch : s.toCharArray()){
            strbld.append(ch);
            if(strbld.length()>=part.length()){
                if(strbld.substring(strbld.length()-part.length()).equals(part)){
                    strbld.delete(strbld.length()-part.length(), strbld.length());
                }
            }
        }
        return strbld.toString();
    }
    public static void main(String[] args) {
        String str = "daabcbaabcbc";
        String part = "abc";
        System.out.println("String After Removing All Occurences Of Substring  : \"" + removeOccurrences(str, part) + "\"");
    }
}