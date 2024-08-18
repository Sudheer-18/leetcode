class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> v1 = {1};
        int i2 = 0, i3 = 0, i5 = 0;
        while (n > 1) {
            int nU = min({v1[i2] * 2, v1[i3] * 3, v1[i5] * 5});
            v1.push_back(nU);
            if (nU== v1[i2] * 2) i2++;
            if (nU == v1[i3] * 3) i3++;
            if (nU == v1[i5] * 5) i5++;

            n--;
        }

        return v1.back();
    }
};