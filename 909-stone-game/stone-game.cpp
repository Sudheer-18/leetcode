class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int i = 0, j = n-1;
        int AS = 0, BS = 0;
        while(i < j) {
            if(i % 2 == 0) {
                AS += max(piles[i],piles[j]);
            }
            else {
                BS += min(piles[i],piles[j]);
            }
            i++;
            j--;
        }
        return AS > BS;
    }
};