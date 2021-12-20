class Solution {  
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        ios_base::sync_with_stdio(false);                          
        cin.tie(NULL);
        vector<vector<int>> answer;

        sort(arr.begin(), arr.end());                               
        int minimum = INT_MAX, p = 0;
        for (int i = 1;i < arr.size();i++)
            if (arr[i] - arr[i - 1] < minimum)
            {
                minimum = arr[i] - arr[i - 1];
                p = i;
            }

        for (int i = p;i < arr.size();i++)                            
            if (arr[i] - arr[i - 1] == minimum)
                answer.push_back({ arr[i - 1],arr[i] });
        return answer;
    }
};