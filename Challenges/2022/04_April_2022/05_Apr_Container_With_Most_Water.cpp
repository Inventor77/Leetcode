class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        int maxArea = 0, area = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            if (height[l] < height[r]) {
                area = height[l] * (r - l);
                l++;
            }
            else {
                area = height[r] * (r - l);
                r--;
            }
            maxArea = max(area, maxArea);

        }
        return maxArea;
    }

};