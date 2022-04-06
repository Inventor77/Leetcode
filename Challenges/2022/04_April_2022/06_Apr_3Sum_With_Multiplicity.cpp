#define M (1e9 + 7)
class Solution {
public:

    int threeSumMulti(int* arr, int arrSize, int target)
    {
        unsigned long long c = 0;
        unsigned long long hash[101] = { 0 };
        for (int i = 0; i < arrSize; i++)
            hash[arr[i]]++;
        for (int i = 0; i <= 100; i++) {
            for (int j = i; j <= 100; j++) {
                int k = target - i - j;
                if (k < 0 || k > 100)
                    continue;
                if (i < j && j < k)
                    c += hash[i] * hash[j] * hash[k];
                else if (i == j && j == k)
                    c += hash[i] * (hash[i] - 1) * (hash[i] - 2) / 6;
                else if (i == j && i != k)
                    c += hash[i] * (hash[i] - 1) / 2 * hash[k];
            }
        }
        return (int)(c % (int)M);
    }
};