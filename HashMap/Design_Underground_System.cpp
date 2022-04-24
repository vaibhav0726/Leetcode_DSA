// An underground railway system is keeping track of customer travel times between different stations. 
// They are using this data to calculate the average time it takes to travel from one station to another.

class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkInIn;
    unordered_map<string, pair<int, int>> path;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInIn[id]= {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn_temp = checkInIn[id];
        checkInIn.erase(id);
        
        string path_name = checkIn_temp.first + "_" + stationName;
        // int new_time = checkIn_temp + t;
        path[path_name].first += t - checkIn_temp.second;
        path[path_name].second += 1; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path_name = startStation + "_" + endStation;
        auto &route = path[path_name];
        return (double) route.first / route.second;
    }
};
