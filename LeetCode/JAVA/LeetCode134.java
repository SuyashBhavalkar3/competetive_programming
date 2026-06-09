// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its
// next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around
// the circuit once in the clockwise direction, otherwise return -1. If there exists a solution,
// it is guaranteed to be unique.

// // Look For Reference In the Book-2 On Pg No 14


public class LeetCode134 {
    public static int circularTripIndex(int[] gas, int[] cost){
        int totalGas = 0;
        int totalCost = 0;
        for(int num : gas)  totalGas+=num;
        for(int nums : cost)    totalCost+=nums;
        if(totalCost>totalGas)  return -1;
        int start = 0;
        int currentGas = 0;
        for(int i=0;i<gas.length;i++){
            currentGas+= gas[i] - cost[i];
            if(currentGas<0){
                currentGas=0;
                start=i+1;
            }
        }
        return start;
    }
    public static void main(String[] args) {
        int[] gas = {1,2,3,4,5};
        int[] cost = {3,4,5,1,2};
        int circular_Trip_Index = circularTripIndex(gas, cost);
        if(circular_Trip_Index==-1){
            System.out.println("Circular Trip Not Possible");
        }
        else{
            System.out.println("Circular Trip Possible, We need To Start from Index "+ circular_Trip_Index);
        }
    }
}
