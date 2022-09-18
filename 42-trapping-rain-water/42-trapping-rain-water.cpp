class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), mL = 0, mR = 0, ans = 0;
        vector<int> maxLeft, maxRight;
        for(int i = 0; i < n; i++) {
            mL = max(mL, height[i]);
            maxLeft.push_back(mL);
        }
        for(int i = n - 1; i >= 0; i--) {
            mR = max(mR, height[i]);
            maxRight.push_back(mR);
        }
        reverse(maxRight.begin(), maxRight.end());
        int trapped = 0;
        for(int i = 0; i < n; i++) {
            trapped = min(maxRight[i], maxLeft[i]) - height[i];
            ans+= trapped;
        }
        return ans;
    }
};