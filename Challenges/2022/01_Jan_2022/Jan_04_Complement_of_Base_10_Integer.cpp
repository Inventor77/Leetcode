class Solution {
public:
    int bitwiseComplement(int n) {
        int i;
        for (i = 0;i <= n;)
        {
            i = (i * 2) + 1;
            if (n <= i)
                break;
        }
        return i - n;
    }

};