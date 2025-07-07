class Solution {
public:
    int maxEvents(vector<vector<int>>& arr) {
       int n=arr.size();
       int maxDay=0;
       priority_queue<int,vector<int>,greater<int>> pq;
       for(int i=0;i<n;i++){
           maxDay=max(maxDay,arr[i][1]);
       }
    sort(begin(arr),end(arr));
       int i=0;int ans=0;
       for(int d=1;i<=maxDay+1;d++){
         while(pq.size() && pq.top()<d){
             pq.pop();
         }
         while(i<n && arr[i][0]==d){
             pq.push(arr[i][1]);
             i++;
         }
         if(pq.size() && pq.top()>=d){
             pq.pop();
             ans++;
         }
         if(pq.size()==0 && i==n){
             break;
         }
       }
       return ans;
    }
};