class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
        int n = mat.size();
        int m = mat[0].size();
        int SolCnt = 0;
        for(int i=0; i<n; i++) {
            SolCnt = 0;
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 1) SolCnt++;
            }
            PQ.push({SolCnt,i});
        }
        // while(!PQ.empty()) {
        //     cout<<PQ.top().first<<" "<<PQ.top().second<<endl;
        //     PQ.pop();
        // }
        while(k--) {
            ans.push_back(PQ.top().second);
            PQ.pop();
        }

        return ans;
    }
};