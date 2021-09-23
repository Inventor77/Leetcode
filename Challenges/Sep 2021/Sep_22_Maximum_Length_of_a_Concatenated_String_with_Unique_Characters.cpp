class Solution {
    // support variables
    int* bits, pos = 0, res = 0, curr = 0, currBit = 0;
    void dfs(vector<string>& arr, int start = 0) {
        // end case: max value achieved
        if (res == 26) return;
        res = max(res, curr);
        // end case: no more combinations to check
        if (start == pos) {
            return;
        }
        for (int i = start; i < pos; i++) {
            if ((currBit & bits[i]) == 0) {
                // updating curr and currBits
                curr += arr[i].size();
                currBit ^= bits[i];
                dfs(arr, i + 1);
                // backtracking curr
                curr -= arr[i].size();
                currBit ^= bits[i];
            }

        }
    }
public:
    int maxLength(vector<string>& arr) {
        // preparing bits
        bits = new int[arr.size()];
        for (auto& s : arr) {
            int bit = 0, tmp;
            for (char c : s) {
                // updating the new bit flag
                tmp = 1 << (c - 'a');
                // checking if s has duplicate words
                if (bit & tmp) {
                    bit = 0;
                    break;
                }
                bit |= tmp;
            }
            // writing bit into bits, if we found no duplicates
            bits[pos++] = bit;
        }
        // moving strings with duplicate characters past pos
        pos--;
        for (int i = 0; i <= pos; i++) {
            if (bits[i]) continue;
            swap(arr[i], arr[pos]);
            swap(bits[i--], bits[pos--]);
        }
        pos++;
        // comparing strings
        dfs(arr);
        return res;
    }
};
