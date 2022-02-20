class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int area = 0;
        while (left < right) {
            area = max(area, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) left += 1;
            else  right -= 1;
        }
        return area;
    }
};