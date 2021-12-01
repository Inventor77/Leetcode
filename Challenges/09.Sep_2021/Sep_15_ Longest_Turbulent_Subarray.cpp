class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();  // Size of array
        if (n < 2)
            return n;
        // if size of array is 0 or 1 then it will return 0 or 1 because single element is turbulant itself

        int i = 0, j = 1;
        // initializing 2 pointers 

        int prev_sign = 2;
        // take random value (which is not possible) as their difference
        // prev_sign is:
        //                     0 if previous element is same as the current element
        //                     -1 if previous element is smaller than current element
        //                     1 if previous element is greater than the current element

        int len = 1;
        // minimum length of turbulent array can be 1

        while (j < n) {
            int s;
            // to store whether the current element is greater or smaller or equal to the previous element
            if (arr[j - 1] > arr[j])
                s = 1;
            else if (arr[j - 1] < arr[j])
                s = -1;
            else {
                s = 0;
                i = j;
                // if previous element is same as current element then we place i pointer on current element
            }
            if (s == prev_sign) {
                i = j - 1;
                // if prev_sign is same as current sign then subarray [i,j] is not turbulant so we have to update i pointer to j for obtaining next subarray
            }
            else {
                len = max(len, j - i + 1);
                // if prev_sign is not same as current sign then subarray [i,j] can be our possible answer. 
                prev_sign = s;
                // updating prev_sign for next iteration
            }
            j++;
        }
        return len;
    }
};