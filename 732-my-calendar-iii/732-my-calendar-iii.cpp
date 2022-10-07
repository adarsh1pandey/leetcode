class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int res=0, cur=0;
        for(auto &e : mp){
            cur += e.second;
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */