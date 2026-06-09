import java.util.ArrayList;
import java.util.List;

public class LeetCode75{
    public static int find_partition(int[] arr, int low, int high){
        int pivot = arr[high];
        int i = low-1;
        for(int j=low;j<high;j++){
            if(arr[j]<pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp2 = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp2;
        return i+1;
    }
    public static void quick_sort(int[] arr, int low, int high){
        if(low<high){
            int partition = find_partition(arr, low, high);
            quick_sort(arr, low, partition-1);
            quick_sort(arr, partition+1, high);
        }
    }
    public static void main(String[] args){
        int[] arr = {2,0,2,1,1,0};
        List<Integer> res = new ArrayList<>();
        quick_sort(arr, 0, arr.length-1);
        for(int num : arr){
            res.add(num);
        }
        System.out.println(res);
    }
}