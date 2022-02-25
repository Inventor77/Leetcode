class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n = version1.size(), m = version2.size();
        int fst = 0, snd = 0;
        while (i < n || j < m) {
            fst = 0, snd = 0;
            while (i < n && version1[i] != '.') {
                fst = fst * 10 + version1[i] - '0';
                i++;
            }
            while (j < m && version2[j] != '.') {
                snd = snd * 10 + version2[j] - '0';
                j++;
            }
            if (fst < snd) return -1;
            if (fst > snd) return 1;
            i++;
            j++;
        }
        return 0;
    }
};
