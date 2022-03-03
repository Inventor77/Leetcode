class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len <= 2) {
            return 0;
        }

        vector<int> arr(len - 1, 0);
        for (int i = 0; i < len - 1; i++) {
            arr[i] = A[i + 1] - A[i];
        }

        int n = 1;
        int res = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                n += 1;
            }

            if (i == arr.size() - 1 || arr[i] != arr[i - 1]) {
                res += sumHelp(n);
                n = 1;
            }
        }

        return res;
    }

    int sumHelp(int n) {
        return n * (n - 1) / 2;
    }
};