class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        return getColor(c1) == getColor(c2);
    }
    bool getColor(const string& coord) {
        int column = coord[0] - 'a';
        int row = coord[1] - '1';
        return (column + row) % 2 == 0;
    }
};
