class Solution {
public:
    vector<int> digits(int temp) {
        vector<int> ans;
        while(temp != 0) {
            int rem = temp % 10;
            ans.push_back(rem);
            temp = temp / 10;
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> V = digits(n);
        map<int,int> mp;
        for(int x : V) mp[x]++; 
        int p = 0;
        while(true) {
            int val = pow(2,p);
            vector<int> V2 = digits(val);
            map<int,int> mp2;
            for(int x : V2) mp2[x]++;
            if(mp == mp2) return true;
            if(val > 1e9) break; 
            p++;
        }
        return false;
    }
};
