class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        string sum;
        int carry = 0;

        int i = n - 1, j = m - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            if (i >= 0) {
                carry += a[i] - '0';
                i -= 1;
            }
            if (j >= 0) {
                carry += b[j] - '0';
                j -= 1;
            }
            sum += (carry % 2) + '0';
            carry /= 2;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};