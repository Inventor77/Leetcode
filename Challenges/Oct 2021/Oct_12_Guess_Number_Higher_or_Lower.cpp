/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int last_val = n;
        int start_val = 1;
        while (last_val >= start_val) {
            int mid_val = start_val + (last_val - start_val) / 2;
            if (guess(mid_val) == 0) return mid_val;
            else if (guess(mid_val) == -1) last_val = mid_val - 1;
            else if (guess(mid_val) == 1) start_val = mid_val + 1;
        }
        return -1;
    }
};