class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> bitmask_position;
        bitmask_position[0] = -1;  
        int bitmask = 0;
        int max_len = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') bitmask ^= (1 << 0);
            else if (s[i] == 'e') bitmask ^= (1 << 1);
            else if (s[i] == 'i') bitmask ^= (1 << 2);
            else if (s[i] == 'o') bitmask ^= (1 << 3);
            else if (s[i] == 'u') bitmask ^= (1 << 4);

            if (bitmask_position.find(bitmask) != bitmask_position.end()) {
                max_len = max(max_len, i - bitmask_position[bitmask]);
            } else {
                bitmask_position[bitmask] = i;
            }
        }
        return max_len;
    }
};
