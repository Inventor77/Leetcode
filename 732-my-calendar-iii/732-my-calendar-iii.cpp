class MyCalendarThree {
private:
    map<int,int> mp;
    int mx;
public:
    MyCalendarThree() {
        mp.clear();
        mx=0;
    }
    
    int book(int s, int e) {
        mp[s]++;
        mp[e]--;
        int cnt=0;
        for (auto [i,v]:mp){
            if (i==e) break;
            cnt+=v;
            mx=max(mx,cnt);
        }
        return mx;
    }
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */