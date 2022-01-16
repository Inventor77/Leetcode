class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0, maxDist = 0, lastPerson;
        while (seats[i] == 0) {
            i++;
        }
        maxDist = i;
        lastPerson = i;
        for (;i < seats.size();i++) {
            if (seats[i] == 1) {
                maxDist = maxDist > (i - lastPerson) / 2 ? maxDist : (i - lastPerson) / 2;
                lastPerson = i;
            }
        }
        maxDist = maxDist > i - lastPerson - 1 ? maxDist : i - lastPerson - 1;
        return maxDist;
    }
};