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


// ---------------------- 0ms Submission ----------------------------

// class Solution {
// public:
//     bool isdigit(char s)
//     {
//         if (s >= '0' && s <= '9')
//             return true;
//         return false;
//     }
//     int calculate(string s) {
//         int n = s.size();
//         stack<int>st;
//         int sum = 0;
//         int sign = 1;
//         int val = 0;
//         for (int i = 0;i < n;i++)
//         {
//             while (i < n && isdigit(s[i]))
//             {
//                 val = val * 10 + (s[i] - '0');
//                 i++;
//             }
//             sum += (val * sign);
//             val = 0;
//             if (s[i] == '-')
//                 sign = -1;
//             else if (s[i] == '+')
//                 sign = 1;
//             else if (s[i] == '(')
//             {
//                 st.push(sum);
//                 sum = 0;
//                 st.push(sign);
//                 sign = 1;
//             }
//             else if (s[i] == ')')
//             {
//                 sum = sum * st.top();
//                 st.pop();
//                 sum += st.top();
//                 st.pop();
//             }
//         }
//         return sum;
//     }
// };

// ------------------------------------------------------------------

// --------------------- 7600KB Submission -------------------------

// class Solution {
// public:
//     int calculate(string& s) {
//         int result = 0;
//         long long int prev = 0;
//         int sign = 1;

//         // <operand, sign>
//         std::vector<std::pair<int, int>> operands;
//         for (const char ch : s) {
//             if (isdigit(ch)) {
//                 prev *= 10;
//                 prev += ch - '0';
//             }
//             else if (ch == ' ') {
//             }
//             else if (ch == '+') {
//                 result += prev * sign;
//                 prev = 0;
//                 sign = 1;
//             }
//             else if (ch == '-') {
//                 result += prev * sign;
//                 prev = 0;
//                 sign = -1;
//             }
//             else if (ch == '(') {
//                 operands.emplace_back(result, sign);
//                 result = 0;
//                 sign = 1;
//             }
//             else if (ch == ')') {
//                 result += prev * sign;
//                 const auto& operand_sign = operands.back();
//                 result *= operand_sign.second;
//                 result += operand_sign.first;
//                 operands.pop_back();
//                 prev = 0;
//                 // sign = 1;
//             }
//         }

//         return result + sign * prev;
//     }
// };

// -----------------------------------------------------------------