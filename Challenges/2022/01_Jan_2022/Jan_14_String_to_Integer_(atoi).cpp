class Solution {
public:
    int myAtoi(string s) {
        int len_ = s.size();
        bool isNeg = false;

        int i = 0;
        while ((i < len_) && (s[i] == ' ')) {
            i++;
        }
        if (i >= len_) {
            return 0;
        }
        if (s[i] == '-') {
            isNeg = true;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        int result = 0;
        for (; i < len_; i++) {
            int digit = s[i] - '0';
            if (digit < 0 || digit > 9) {
                result = isNeg ? result * (-1) : result;
                return result;
            }
            if (result > (INT_MAX - digit) / 10) {
                result = isNeg ? INT_MIN : INT_MAX;
                return result;
            }
            result = result * 10 + digit;
        }
        result = isNeg ? result * (-1) : result;
        return result;
    }
};