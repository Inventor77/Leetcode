class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0, n = people.size();

        int p1 = 0, p2 = n - 1;
        while (p1 < p2)
        {
            if (people[p1] + people[p2] <= limit)
                boat++, p1++, p2--;
            else
                boat++, p2--;
        }
        if (p1 == p2)
            boat++;
        return boat;
    }
};