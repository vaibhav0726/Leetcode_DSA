class ParkingSystem {
private: 
    vector<int> cars;
public:
    ParkingSystem(int big, int medium, int small) {
        cars.push_back(big);
        cars.push_back(medium);
        cars.push_back(small);
    }
    
    bool addCar(int carType) {
        if(cars[carType-1] <= 0) return false;
        else {
            cars[carType-1]--;
            return true;
        }
    }
};