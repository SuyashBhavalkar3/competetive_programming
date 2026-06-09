// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars.
// Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

// Note: The characters in the array beyond the returned length do not matter and should be ignored.


// Look For Reference In the Book-2 On Pg No 28-29



public class LeetCode443 {
    public static int compressedInt(char[] chars){
        int n = chars.length;
        int idx = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            char charac = chars[i];
            while(i<n && chars[i]==charac){
                cnt++;
                i++;
            }
            if(cnt==1){
                chars[idx++] = charac;
            }
            else{
                chars[idx++] = charac;
                String diString = Integer.toString(cnt);
                for(char ch : diString.toCharArray()){
                    chars[idx++] = ch;
                }
            }
            i--;
        }
        return idx;
    }
    public static void main(String[] args) {
        char[] chars = {'a','a','b','b','c','c','c'};
        System.out.println("Compressed String Length Is : " + compressedInt(chars));
    }
}
