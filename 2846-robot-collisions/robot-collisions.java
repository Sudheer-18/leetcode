class Solution {
    public List<Integer> survivedRobotsHealths(int[] pos, int[] h, String dir) {
        ArrayList<Integer> ans = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        int n = h.length;

        // Create an array of indices and sort them based on positions
        Integer[] ids = new Integer[n];
        for (int i = 0; i < n; i++) {
            ids[i] = i;
        }
        Arrays.sort(ids, Comparator.comparingInt(i -> pos[i]));

        for (int id : ids) {
            if (dir.charAt(id) == 'R') {
                st.push(id);
            } else {
                while (!st.isEmpty() && h[id] > 0) {
                    int top = st.peek();
                    if (h[id] > h[top]) {
                        h[id]--;
                        h[top] = 0;
                        st.pop();
                    } else if (h[id] < h[top]) {
                        h[top]--;
                        h[id] = 0;
                    } else {
                        h[id] = 0;
                        h[top] = 0;
                        st.pop();
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (h[i] > 0) {
                ans.add(h[i]);
            }
        }
        return ans;
    }
}