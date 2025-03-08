class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int maxCoins = 0;
        int n = piles.size();
        sort(piles.begin(),piles.end());
        for(int i = n / 3; i < n; i+=2) maxCoins += piles[i];
        return maxCoins; 
    }
};