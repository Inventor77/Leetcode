class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> a;
        for (int i = 0; i < nums2.size() - 1; i++)
        {
            bool greater_is_present = false;
            for (int j = i + 1; j < nums2.size(); j++)
            {
                if (nums2[i] < nums2[j] && i != j)
                {
                    a.push_back(make_pair(nums2[i], nums2[j]));
                    greater_is_present = true;
                    break;
                }
            }
            if (!greater_is_present)
            {
                a.push_back(make_pair(nums2[i], -1));
            }
        }
        auto it = --nums2.end();
        a.push_back(make_pair(*it, -1));
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < a.size(); j++)
            {
                if (nums1[i] == a[j].first)
                {
                    ans.push_back(a[j].second);
                    break;
                }
            }
        }
        return ans;
    }
};