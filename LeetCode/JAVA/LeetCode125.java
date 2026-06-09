// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
// and removing all non-alphanumeric characters, it reads the same forward and backward.
// Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.


import java.util.Scanner;

public class LeetCode125{
    public static boolean findPalindrome(String s){

        int low = 0, high = s.length()-1;
        while(low<high){
            if(!Character.isLetterOrDigit(s.charAt(low))){
                low++;
                continue;
            }
            if(!Character.isLetterOrDigit(s.charAt(high))){
                high--;
                continue;
            }
            if(Character.toLowerCase(s.charAt(low))!=Character.toLowerCase(s.charAt(high))){
                return false;
            }
            low++;
            high--;
        }
        return true;

    }

    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter String : ");
            String str = sc.nextLine();
            System.out.println("String Is Palindrome : " + findPalindrome(str));
        }
    }
}