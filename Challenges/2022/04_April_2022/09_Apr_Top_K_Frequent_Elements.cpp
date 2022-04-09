class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int x : nums) {
            freqMap[x]++;
        }
        auto comp = [&freqMap](auto& lhs, auto& rhs) {
            return freqMap[lhs] > freqMap[rhs];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (auto& thing : freqMap) {
            pq.push(thing.first);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};