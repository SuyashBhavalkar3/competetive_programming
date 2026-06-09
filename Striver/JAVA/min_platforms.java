// Given the arrival and departure times of all trains reaching a particular railway station,
// determine the minimum number of platforms required so that no train is kept waiting.
// Consider all trains arrive and depart on the same day.

// In any particular instance, the same platform cannot be used for both the departure of
// one train and the arrival of another train, necessitating the use of different platforms in such cases.

// Look For Reference In the Book-3 On Pg No 16-17


import java.util.Arrays;

public class min_platforms{
    public static int min_platform(int[] arrival, int[] departure){
        int n = arrival.length;
        if(n==0)    return 0;
        Arrays.sort(arrival);
        Arrays.sort(departure);
        int i = 0, j = 0;
        int maxCnt = 0, cnt = 0;
        while(i<n && j<n){
            if(arrival[i]<departure[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxCnt = Math.max(maxCnt, cnt);
        }
        return maxCnt;
    }
    public static void main(String[] args) {
        int [] a = {900, 940,  950,  1100, 1500, 1800};
        int [] b = {910, 1200, 1120, 1130, 1900, 2000};
        int min = min_platform(a, b);
        System.out.println("The minimum platforms we need to allocate are : " + min);
    }
}