class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < 12; i++) v.push_back(arr[i] + v[i]);
    int aaM = stoi(arriveAlice.substr(0, 2)),
        aaD = stoi(arriveAlice.substr(3, 2)),
        laM = stoi(leaveAlice.substr(0, 2)),
        laD = stoi(leaveAlice.substr(3, 2)),
        abM = stoi(arriveBob.substr(0, 2)),
        abD = stoi(arriveBob.substr(3, 2)),
        lbM = stoi(leaveBob.substr(0, 2)),
        lbD = stoi(leaveBob.substr(3, 2));
    int aaDays = v[aaM - 1] + aaD,
        alDays = v[laM - 1] + laD,
        baDays = v[abM - 1] + abD,
        blDays = v[lbM - 1] + lbD;

    int maxA = max(aaDays, baDays), minL = min(alDays, blDays);
    int ans = minL - maxA + 1;
    return max(0, ans);
}
};