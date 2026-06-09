// Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline ,
// Jobs[i][2] represents Profit associated with that job.
// Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

// The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.

// Look For Reference In the Book-3 On Pg No 26-27


import java.util.Arrays;

public class job_sequencing {
    public static class Pair{
        int jobs, profit;
        Pair(int a, int b){
            jobs = a;
            profit = b;
        }
    }
    public static Pair job_sequencing1(int[][] jobs){
        int n = jobs.length;
        if(n==0)    return new Pair(-1, -1);
        Arrays.sort(jobs, (a,b)->Integer.compare(b[2], a[2]));
        int maxDead = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int dead = jobs[i][1];
            maxDead = Math.max(maxDead, dead);
        }
        int[] slots = new int[maxDead+1];
        Arrays.fill(slots, -1);
        int job = 0;
        int profit = 0;
        for(int i=0;i<n;i++){
            for(int j = jobs[i][1];j>0;j--){
                if(slots[j]==-1){
                    slots[j] = i;
                    job++;
                    profit+=jobs[i][2];
                    break;
                }
            }
        }
        return new Pair(job, profit);
    }
    public static void main(String[] args) {
        int[][] jobs = {{1, 2, 100},
                        {2, 1, 19}, 
                        {3, 2, 27}, 
                        {4, 1, 25}, 
                        {5, 1, 15}};
        Pair jobAndProfit = job_sequencing1(jobs);
        System.out.println("The Pair Of Job : Profit At Most Is -> " + jobAndProfit.jobs+ " : " + jobAndProfit.profit);
    }
}
