class Solution {
public:
    set<string> DS;
    int cnt = 0;
    void PermutationsCount(string s,int idx,int n) {
        if(idx == n) return ;
        if(s.size() != 0) {
            if(DS.find(s) == DS.end()) cnt++;
            DS.insert(s);
        }
        for(int i = idx; i < n; i++) {
            swap(s[i],s[idx]);
            PermutationsCount(s,idx + 1, n);
            swap(s[i],s[idx]);
        }
    }
    void helper(string tiles,string s,int idx, int n) {
        if(idx >= n) {
            PermutationsCount(s,0,s.size());
            return ;
        }
        helper(tiles,s+tiles[idx],idx + 1,n);
        helper(tiles,s,idx + 1,n);
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        helper(tiles,"",0,n);
        return cnt;
    }
};