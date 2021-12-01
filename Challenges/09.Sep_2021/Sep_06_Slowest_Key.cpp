class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = keysPressed.size();
        unordered_map<char, int> mp;
        int mxT = 0;
        for (int i = 0; i < n; i++)
        {
            char x = keysPressed[i];
            if (i == 0) {
                mp[x] = releaseTimes[i];
            }
            else
            {
                mp[x] = max(mp[x], releaseTimes[i] - releaseTimes[i - 1]);
            }
            mxT = max(mxT, mp[x]);
        }
        char ans = 0;
        for (auto x:mp)
        {
            char key = x.first;
            int time = x.second;
            if (time == mxT)
            {
                if (ans == '0') ans = key;
                else
                {
                    ans = max(ans, key);
                }
                
            }
            
        }
        return ans;
    }
};


// ----------------- 0ms Submission -------------------

// static const auto speedup = []() {
//     ios_base::sync_with_stdio(false);
//     cout.tie(NULL);
//     cin.tie(NULL);
//     return NULL;
// }();
// class Solution {
// public:
//     char slowestKey(vector<int>& releaseTimes, string keysPressed) {
//         char res = keysPressed[0];
//         int max = releaseTimes[0];
//         for (int i = 0; i < releaseTimes.size() - 1; ++i) {
//             int tmp = releaseTimes[i + 1] - releaseTimes[i];
//             if (tmp > max)
//             {
//                 max = tmp;
//                 res = keysPressed[i + 1];
//             }
//             else if (tmp == max && keysPressed[i + 1] > res)
//             {
//                 res = keysPressed[i + 1];
//             }
//         }
//         return res;
//     }
// };

// ----------------------------------------------------

// --------------------- 10400KB Submission --------------

// class Solution {
// public:
//     char slowestKey(vector<int>& releaseTimes, string keysPressed) {
//         int n = keysPressed.size();
//         int time = releaseTimes[0];
//         char maxi = keysPressed[0];
//         for (int i = 1; i < n; i++)
//         {
//             int  diff = releaseTimes[i] - releaseTimes[i - 1];
//             if (diff > time || (diff == time && maxi < keysPressed[i]))
//             {
//                 time = diff; maxi = keysPressed[i];
//             }
//         }
//         return maxi;
//     }
// };

// -------------------------------------------------------