// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

// Look For Reference In the Book On Pg No 102-103



import java.util.ArrayList;
import java.util.List;

public class LeetCode131{
    public static boolean isPalidrome(String str, int start, int end){
        while(start<end){
            if(str.charAt(start)!=str.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    public static void findPartitions(int start, String str, List<String> partition, List<List<String>> allPartitions){
        if(start==str.length()){
            allPartitions.add(new ArrayList<>(partition));
            return;
        }
        for(int end = start;end<str.length();end++){
            if(isPalidrome(str, start, end)){
                partition.add(str.substring(start, end+1));
                findPartitions(end+1, str, partition, allPartitions);
                partition.remove(partition.size()-1);
            }
        }
    }
    public static List<List<String>> palindrome_partitioning(String str){
        List<List<String>> allPartitions = new ArrayList<>();
        findPartitions(0, str, new ArrayList<>(), allPartitions);
        return allPartitions;
    }
    public static void main(String[] args) {
        String str = "suyash";
        List<List<String>> res = palindrome_partitioning(str);
        System.out.println(res);
    }
}