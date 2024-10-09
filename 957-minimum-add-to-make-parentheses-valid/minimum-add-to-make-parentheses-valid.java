class Solution {
    public int minAddToMakeValid(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        int cb = 0;
        for(int i=0;i<n;i++) {
            char ch = s.charAt(i);
            if(ch == '(' && st.isEmpty())  st.push(ch);
              else if(ch == ')' && st.isEmpty()) cb++;
            else if(ch == ')' && st.peek() == '(') st.pop();
            else st.push('(');
        }
        return st.size()+cb;
    }
}