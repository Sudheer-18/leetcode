class MyCalendar {
public:
    vector<pair<int,int>>arr;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(auto num : arr) {
            int a = num.first;
            int b = num.second;
            if(start < b && end > a) {
                return false;
            }
        }
        arr.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */