class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        if (k == 1) 
        {
            string ans = s;
            for (int i = 0; i < n; i++)
            {
                string res = s.substr(i) + s.substr(0, i);
                ans = min(ans, res);
            }
            return ans;
        }
        sort(s.begin(), s.end());
        return s;
    }
};

// -------------------- 6100KB Submission -------------------------

// class Solution {
// public:
//     string orderlyQueue(string s, int k) {
//         if (k == 1) {
//             string r = s;
//             for (int i = 1;i < s.length();i++) {
//                 char c = s[0];
//                 s.erase(s.begin());
//                 s.push_back(c);
//                 if (s < r) {
//                     r = s;
//                 }
//             }
//             return r;
//         }

//         sort(s.begin(), s.end());
//         return s;


//     }
// };

// -------------------------------------------------------------------