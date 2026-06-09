import java.util.HashMap;

public class count_the_number_of_subarrays_with_given_xor_K {
    public static int count_subarray_with_sumK(int[] arr, int k){
        int XORTotal = 0;
        int count = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        for(int i=0;i<arr.length;i++){
            XORTotal^=arr[i];
            if(map.containsKey(XORTotal^k)){
                count+=map.get(XORTotal^k);
            }
            map.put(XORTotal, map.getOrDefault(XORTotal, 0)+1);
        }
        return count;
    }
    public static void main(String[] args) {
        int[] arr = {4, 2, 2, 6, 4};
        int k = 6;
        System.out.println("The Number Of SubArrays With Given XOR K Is : " + count_subarray_with_sumK(arr, k));
    }
}
