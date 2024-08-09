class Solution {
    public boolean magic_squares(int[][] arr, int row, int col) {
        int[] pre_arr = new int[8];
        int k = 0;

        for (int i = 0; i < 3; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += arr[row + i][col + j]; 
            }
            pre_arr[k] = sum;
            k += 1;
        }

        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int i = 0; i < 3; i++) {
                sum += arr[row + i][col + j]; 
            }
            pre_arr[k] = sum;
            k += 1;
        }

        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += arr[row + i][col + i];
        }
        pre_arr[k] = sum;
        k += 1;

        sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += arr[row + i][col + 2 - i];
        }
        pre_arr[k] = sum;
        k += 1;

        for (int i = 0; i < pre_arr.length - 1; i++) {
            if (pre_arr[i] != pre_arr[i + 1]) return false;
        }

        boolean[] visited = new boolean[10];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = arr[row + i][col + j];
                if (num < 1 || num > 9 || visited[num]) {
                    return false;
                }
                visited[num] = true;
            }
        }

        return true;
    }

    public int numMagicSquaresInside(int[][] arr) {
        int n = arr.length;
        int m = arr[0].length;
        if (n < 3 || m < 3) return 0; 
        int tot_cnt = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (arr[i + 1][j + 1] == 5 && magic_squares(arr, i, j)) {
                    tot_cnt += 1;
                }
            }
        }  
        return tot_cnt;
    }
}
