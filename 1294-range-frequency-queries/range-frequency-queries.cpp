class SegmentTree {
public:
    int Size;
    vector<unordered_map<int, int>> Tree;
    SegmentTree(vector<int>& V) {
        Size = V.size();
        Tree.resize(4 * Size);
        Build(0, 0, Size - 1, V);
    }

    void Build(int idx, int start, int end, vector<int>& V) {
        if (start == end) {
            Tree[idx][V[start]] = 1; 
            return;
        }
        int mid = (start + end) / 2;
        Build(2 * idx + 1, start, mid, V);
        Build(2 * idx + 2, mid + 1, end, V);
        Tree[idx] = Tree[2 * idx + 1];
        for (auto p : Tree[2 * idx + 2]) {
            Tree[idx][p.first] += p.second;
        }
    }

    int Query(int idx, int s, int e, int Qs, int Qe, int val) {
        if (Qs > e || Qe < s) return 0; 
        if (Qs <= s && Qe >= e) {
            return Tree[idx][val]; 
        }

        int mid = (s + e) / 2;
        return Query(2 * idx + 1, s, mid, Qs, Qe, val) +
               Query(2 * idx + 2, mid + 1, e, Qs, Qe, val);
    }
};

class RangeFreqQuery {
public:
    SegmentTree segTree;
    RangeFreqQuery(vector<int>& arr) : segTree(arr) {}
    int query(int left, int right, int value) {
        return segTree.Query(0, 0, segTree.Size - 1, left, right, value);
    }
};
