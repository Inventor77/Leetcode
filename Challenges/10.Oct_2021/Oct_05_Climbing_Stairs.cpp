class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        int c = a + b;

        for (int i = 0; i < n - 1; i++) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
    
};