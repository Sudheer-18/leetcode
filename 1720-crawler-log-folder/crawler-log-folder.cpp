class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        // Stack<String> s  = new Stack<String>();
        int n = logs.size();
        for(int i=0;i<n;i++) {
            if(logs[i]=="../" && step==0) continue;
            if(logs[i] == "../" && step > 0) step-=1;
            else if(logs[i] == "./") continue;
            else {
                step+=1;
            } 
        }
        return  step;

    }
};