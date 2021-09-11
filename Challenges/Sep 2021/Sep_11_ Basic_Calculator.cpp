class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        long ans = 0, sign = 1;
        stack<int> nums, ops;
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                long sum = 0;
                while (i < n && isdigit(s[i]))
                {
                    sum = (sum * 10 + s[i] - '0');
                    i++;
                    ans += sum * sign;
                    i--;
                }
            }
            else
            {
                if (s[i] == '+') sign = 1;
                else if (s[i] == '-') sign = -1;
                else if (s[i] == '(')
                {
                    nums.push(ans);
                    ans = 0;
                    ops.push(sign);
                    sign = -1;
                }
                else if (s[i] == ')')
                {
                    ans = ops.top() * ans + nums.top();
                    ops.pop();
                    nums.pop();
                }
            }       
        }
        return ans;
    }
};






class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> st; // pair(prev_calc_value , sign before next bracket () )

        long long int sum = 0;
        int sign = +1;

        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];

            if (isdigit(ch))
            {
                long long int num = 0;
                while (i < s.size() and isdigit(s[i]))
                {
                    num = (num * 10) + s[i] - '0';
                    i++;
                }
                i--; // as for loop also increase i , so if we don't decrease i here a sign will be skipped
                sum += (num * sign);
                sign = +1; // reseting sign
            }
            else if (ch == '(')
            {
                // Saving current state of (sum , sign) in stack
                st.push(make_pair(sum, sign));

                // Reseting sum and sign for inner bracket calculation
                sum = 0;
                sign = +1;
            }
            else if (ch == ')')
            {
                sum = st.top().first + (st.top().second * sum);
                st.pop();
            }
            else if (ch == '-')
            {
                // toggle sign
                sign = (-1 * sign);
            }
        }
        return sum;
    }
};