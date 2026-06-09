// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Look For Reference In the Book-3 On Pg No 60-61


import java.util.ArrayList;
import java.util.List;

public class LeetCode60 {
    public static String get_permutation(int n, int k){
        int factorial = 1;
        List<Integer> numbers = new ArrayList<>();
        for(int i=1;i<n;i++){
            numbers.add(i);
            factorial = factorial*i;
        }
        numbers.add(n);
        String res = "";
        k = k-1;
        while(true){
            res+=numbers.get(k/factorial).toString();
            numbers.remove(k/factorial);
            if(numbers.size()==0){
                break;
            }
            k = k%factorial;
            factorial = factorial/numbers.size();
        }
        return res;
    }
    public static void main(String[] args) {
        int n = 4;
        int k = 9;
        String res = get_permutation(n, k);
        System.out.println("The "+k+"th permutation is : " + res);
    }
}
