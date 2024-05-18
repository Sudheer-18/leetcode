class Solution {
public:
    int longestValidParentheses(string s) {
        int i=0,max1=0;
	stack<int>st;
	st.push(-1);
	while(i<s.size())
	{
		if(s[i]=='(')
		{
			st.push(i);
		}
		else {
			st.pop();
			if(st.empty())
			{
				st.push(i);
			}
			else {
				max1=max(max1,i-st.top());
			}
		}
		i+=1;
	}
	// cout<<max1<<endl;
    return max1;
    }
};