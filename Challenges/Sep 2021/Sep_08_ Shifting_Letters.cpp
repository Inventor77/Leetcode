class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        for (int i = n - 2; i >= 0; i--) {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }
        for (int i = 0; i < n;i++) {
            s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return s;
    }
};



// -------------------- 20ms Submission --------------

// class Solution {
// public:
//     string shiftingLetters(string s, vector<int>& shifts) {
//         for (int i = shifts.size() - 2; i >= 0; i--) {
//             shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
//         }

//         for (int i = 0; i < s.size(); i++) {
//             s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
//         }

//         return s;
//     }
// };

// ---------------------------------------------------


// -------------- 20000KB Submission -----------------

// class Solution {
// public:
//     string shiftingLetters(string s, vector<int>& b) {
//         long long i;
//         for (i = b.size() - 2;i >= 0;i--)
//         {
//             b[i] = (1L * b[i] + b[i + 1]) % 26;
//         }
//         for (i = 0;i < s.size();i++)
//         {
//             long long v = 1L * (s[i] - 'a') + b[i];
//             v %= 26;
//             s[i] = 'a' + v;
//         }
//         return s;
//     }
// };

// ---------------------------------------------------