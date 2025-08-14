class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n+1,false);
        queue<int>q;
        vis[s] = true;
        q.push(s);
        while(!q.empty()) {
            int curr = q.front();
            if(curr == d) return true;
            for(auto x : adj[curr]) {
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                }
            }
            q.pop();
        }

        return false;
    }
};