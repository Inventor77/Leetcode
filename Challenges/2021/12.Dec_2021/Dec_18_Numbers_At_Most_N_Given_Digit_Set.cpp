class Solution {
public:

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string strN = to_string(n);
        int ans = 0;

        for (int i = 1; i < strN.size(); i++)
            ans += pow(digits.size(), i);

        allNdigNumbers(digits, strN.size(), ans, strN);

        return ans;
    }

    void allNdigNumbers(vector<string>& digits, int nSize, int& ans, string StrN) {

        for (int i = 0; i < nSize; i++) {
            bool pref = false;

            for (auto& chr : digits)
                if (chr[0] < StrN[i]) ans += pow(digits.size(), nSize - i - 1);
                else if (chr[0] == StrN[i]) { pref = true; break; }

            if (!pref) return;
        }
        ans++;
    }
};