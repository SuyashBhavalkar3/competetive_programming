// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words.
// The returned string should only have a single space separating the words. Do not include any extra spaces.


// Look For Reference In the Book On Pg No 80-81



public class LeetCode151{
    public static void main(String[] args) {
        String line = "the sky is blue";
        String[] words = line.split(" ");
        int start = 0;
        int end = words.length-1;
        int line_length = words.length;
        while(start<end){
            String temp = words[start];
            words[start] = words[end];
            words[end] = temp;
            start++;
            end--;
        }
        int count=0;
        StringBuilder strbuil = new StringBuilder();
        for(String word : words){
            strbuil.append(word);
            count++;
            if(count<line_length){
                strbuil.append(" ");
            }
        }
        System.out.println(strbuil.toString());
    }
}