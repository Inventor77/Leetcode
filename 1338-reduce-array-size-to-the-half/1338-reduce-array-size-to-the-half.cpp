class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> v;
        for(int i = 0; i < arr.size(); i++) {
            v[arr[i]]++;
        }
        vector<int> elem;
        for(auto it : v) {
            elem.push_back(it.second);
        }
        sort(elem.begin(), elem.end(), greater<int>());
        int sum = 0, ans = 0;
        for(int i = 0; i < elem.size(); i++) {
            if(sum < arr.size() / 2)  {
                sum += elem[i];
                ans++;
            }
            else break;
        }
        return ans;
    }
};