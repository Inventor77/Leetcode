class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        int res = 0;
        unordered_map <string, int> mp;

        for (int i = 0; i < emails.size(); i++)
        {
            string temp = emails[i];
            string s = "";
            int x = 1;

            for (int j = 0; temp[j]; j++)
            {
                if (temp[j] == '+')
                {
                    int k = j;
                    while (temp[k] != '@')
                        k++;
                    j = k;
                }

                if (temp[j] == '@')
                    x = 0;
                if (temp[j] == '.' && x)
                    continue;

                s += temp[j];
            }

            if (mp[s])
                continue;

            mp[s]++;
            res++;
        }
        return res;
    }
};
