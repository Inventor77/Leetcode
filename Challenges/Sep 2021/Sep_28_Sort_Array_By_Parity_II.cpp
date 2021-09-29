class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& ns) {
        int i = 0, j = 1, lmt = ns.size();
        while (true) {
            while (i < lmt && !(ns[i] & 1)) i += 2;
            while (j < lmt && (ns[j] & 1)) j += 2;
            if (i < lmt && j < lmt) swap(ns[i], ns[j]);
            else break;
        }
        return ns;
    }
};