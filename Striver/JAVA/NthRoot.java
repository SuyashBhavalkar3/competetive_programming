public class NthRoot {
    public static double findPower(double mid, int n) {
        double ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * mid;
        }
        return ans;
    }

    public static int findNthRoot(int number, int n) {
        if (n == 1) {
            return number;
        }
        if (number == 1) {
            return 1;
        }
        double low = 1;
        double high = number;
        double diff = 1e-6;
        while ((high - low) > diff) {
            double mid = low + (high - low) / 2;
            double power = findPower(mid, n);
            if (power > number) {
                high = mid;
            } else {
                low = mid;
            }

        }
        return (int) Math.round(low + (high - low) / 2.0);
    }

    public static void main(String[] args) {
        int number = 27;
        int n = 3;
        int root = findNthRoot(number, n);
        if (root != -1) {
            System.out.println("The " + n + "th root of " + number + " is : " + root);
        }
    }
}