class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long ans = 0;
        priority_queue <int,vector <int>,greater <int>> pq;
        vector <pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({efficiency[i],speed[i]});
        sort(v.rbegin(),v.rend());
        long long topksum =0;
        for(int i=0;i<n;i++){
            int cur_min = v[i].first;
            long long speed_sum = 1LL*v[i].second + topksum;
            ans = max(ans,1LL*speed_sum*cur_min);
            pq.push(v[i].second);
            topksum+=1LL*v[i].second;
            if(pq.size()>k-1) {
                topksum -=1LL*pq.top();
                pq.pop();
            }
        }
        int mod = 1000000007;
        ans%=mod;
        return ans;
    }
};