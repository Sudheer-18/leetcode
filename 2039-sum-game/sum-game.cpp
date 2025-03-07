class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int FirSum = 0, SecSum = 0, FQ = 0 , SQ = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')  FQ++;
            else FirSum += (num[i] - '0');
            if (num[n / 2 + i] == '?') SQ++;
            else SecSum += (num[n / 2 + i] - '0');
        }
        int diff = FirSum - SecSum;
        return (diff * 2 != (SQ - FQ) * 9);
    }
};
