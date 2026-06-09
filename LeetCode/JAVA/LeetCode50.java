// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

// Look For Reference In the Book On Pg No 125


public class LeetCode50{
    public static double res = 1;
    public static double powHelper(double x, long n){
        if(n==0)    return 1;
        if(n==1)    return x;
        double half = powHelper(x, n/2);
        if(n%2==0)  return half*half;
        return half*half*x;
    }
    public static double myPow(double x, int n){
        long N = n;
        if(N<0){
            N = -N;
            x = 1/x;
        }
        return powHelper(x, N);
    }
    public static void main(String[] args) {
        double x = 2;
        int n = -2;
        myPow(x,n);
        System.out.println(x + " raise to " + n + " is : " + myPow(x, n));
    }
}