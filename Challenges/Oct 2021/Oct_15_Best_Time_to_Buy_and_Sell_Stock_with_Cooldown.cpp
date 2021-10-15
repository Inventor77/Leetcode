int solveDP2(vector<int>& prices) {

    int dp[3][2];

    for (int i = 0;i <= 2;i++) {
        for (int j = 0;j <= 1;j++) {
            dp[i][j] = 0;
        }
    }

    for (int day = (int)prices.size() - 1;day >= 0;day--) {
        for (int buy = 0;buy <= 1;buy++) {


            int& ans = dp[day % 3][buy];


            // First Choice
            int ans1 = dp[(day + 1) % 3][buy]; // no transaction this say


            // Second Choice
            int ans2 = 0; // doing the required transaction this day

            if (buy) {
                ans2 = -prices[day] + dp[(day + 1) % 3][0];
            }            
else {
                ans2 = prices[day] + dp[(day + 2) % 3][1];
            }

            ans = max(ans1, ans2);

        }
    }

    return dp[0][1];


}


int maxProfit(vector<int>& prices) {

    int ans = 0;

    // Recursive Solution 
    // ans = solveRec(prices, 0, true);

    // Memoization Solution
    // vector<vector<int>> memo(prices.size() + 2, vector<int>(2, -1));
    // ans = solveMemo(prices, 0, true, memo);

     // DP solution with O(N) space
    // ans = solveDP1(prices);

    // DP solution with O(1) space
    ans = solveDP2(prices);


    return ans;

}
};
