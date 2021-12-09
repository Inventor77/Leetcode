class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue <int> q;
        q.push(start);
        set<int> visited;
        visited.insert(start);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (arr[curr] == 0) return true;
            if (curr + arr[curr] < n && !visited.count(curr + arr[curr])) {
                q.push(curr + arr[curr]);
                visited.insert(curr + arr[curr]);
            }
            if (curr - arr[curr] >= 0 && !visited.count(curr - arr[curr])) {
                q.push(curr - arr[curr]);
                visited.insert(curr - arr[curr]);
            }
        }
        return false;
    }
};  