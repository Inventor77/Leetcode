class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor1 = 0, Xor2 = 0, i;
        for (const int n : nums) Xor1 ^= n;
        for (int bit = 0; bit < 32; bit++)
            if (Xor1 & 1 << bit) {
                i = bit;
                break;
            }

        for (const int n : nums)
            if (n & 1 << i)
                Xor2 ^= n;

        return { Xor1 ^ Xor2, Xor2 };
    }
};