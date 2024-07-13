class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        int flag = 0;
        for(int i = 0 ; i < asteroids.length; i++)
        {
            while(!st.isEmpty() && asteroids[i] < 0  && st.peek()>0)
            {
                int val = asteroids[i]+st.peek();
                if(val < 0)
                st.pop();
                else if(val > 0)
                asteroids[i] = 0;
                else
                {
                    asteroids[i] = 0;
                    st.pop();
                }
            }
            if(asteroids[i]!=0)
            st.push(asteroids[i]);
        }
        int s = st.size();
        int[] a = new int[s];
        for(int i = s - 1 ; i >= 0 ;i--) {
            a[i]=st.pop();
        }
        return a;
    }
}