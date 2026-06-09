// You have n items; the i-th item has value val[i] and weight wt[i].

// A knapsack can carry at most capacity units of weight.

// You may take any fraction of an item (i.e. split items).

// Return the maximum total value that can be placed in the knapsack, rounded to exactly 6 decimal places.

// Look For Reference In the Book-3 On Pg No 28-29


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class fradtional_knapsack{

    public static class Pair{
        int first;
        int second;
        Pair(int a, int b){
            first = a;
            second = b;
        }
    }

    public static double fractional_knaps(int[] val, int[] weight, int capacity){
        int n = val.length;
        if(n==0||capacity==0){
            return 0;
        }
        List<Pair> pair = new ArrayList<>();
        for(int i=0;i<n;i++){
            pair.add(new Pair(val[i], weight[i]));
        }
        Collections.sort(pair, (a, b)->Double.compare(b.first*a.second,a.first*b.second));
        for(Pair p : pair){
            System.out.println(p.first+", "+p.second);
        }
        double totalVal = 0;
        for(int i=0;i<n;i++){
            if(pair.get(i).second<=capacity){
                totalVal+=pair.get(i).first;
            }
            else{
                totalVal+=((double)pair.get(i).first/pair.get(i).second)*capacity;
                break;
            }
            capacity-=pair.get(i).second;
        }
        return totalVal;
    }

    public static void main(String[] args) {
        int[] val = {60, 100, 120};
        int[] weight = {10, 20, 30};
        int capacity = 50;
        double valueMax = fractional_knaps(val, weight, capacity);
        System.out.println("Total Capacity Of Fractional Knapsack is : " + valueMax);
    }

}