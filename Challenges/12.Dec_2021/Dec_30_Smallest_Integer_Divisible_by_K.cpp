class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if ((k & 1) == 0) return -1;
        int len = 1, n = 1;
        for (int i = 1; i <= k; ++i)
        {
            if (n % k == 0) return len;
            n = (n * 10 + 1) % k, len += 1;
        }
        return -1;
    }
};