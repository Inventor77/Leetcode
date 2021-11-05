class Solution {
public:
    int arrangeCoins(int n) {
        return int(sqrt(1 + 8l * n) - 1) >> 1;
    }
};