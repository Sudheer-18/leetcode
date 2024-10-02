import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        int[] tmp = new int[n];
        for (int i = 0; i < n; i++) tmp[i] = arr[i];
        Arrays.sort(tmp);
        HashMap<Integer, Integer> hm = new HashMap<>();
        int rnk = 1;
        for (int i = 0; i < n; i++) {
            if (!hm.containsKey(tmp[i])) {
                hm.put(tmp[i], rnk);
                rnk++;
            }
        }
        for (int i = 0; i < n; i++) {
            arr[i] = hm.get(arr[i]);
        }
        
        return arr;
    }
}
