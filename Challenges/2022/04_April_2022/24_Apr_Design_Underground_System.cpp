class UndergroundSystem {
private:
    map<pair<string, string>, vector<int>> time;
    map<int, pair<int, string>> customer;
public:
    UndergroundSystem() {
    }

    void checkIn(int id, string startTime, int t) {
        customer[id] = { t, startTime };
    }
    void checkOut(int id, string endStation, int endTime) {
        int startTime = customer[id].first;
        string startStation = customer[id].second;
        time[{startStation, endStation}].push_back(endTime - startTime);
    }
    double getAverageTime(string startStation, string endStation) {
        double res = 0.0;
        int size = time[{startStation, endStation}].size();
        for (auto x : time[{startStation, endStation}])
            res += x;
        res /= size;
        return res;
    }
};
