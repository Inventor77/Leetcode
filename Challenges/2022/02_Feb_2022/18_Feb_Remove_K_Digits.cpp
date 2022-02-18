class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() <= k)
            return "0";
        if (k == 0)
            return num;
        string stack;
        for (int i = 0; i < num.length(); ++i) {
            while (k > 0 && !stack.empty() && num[i] < stack.back())
                stack.pop_back(), --k;
            if (!stack.empty() || num[i] != '0')
                stack.push_back(num[i]);
        }
        stack.resize(std::max((ssize_t)stack.length() - k, (ssize_t)0));
        return stack.empty() ? "0" : stack;
    }
};