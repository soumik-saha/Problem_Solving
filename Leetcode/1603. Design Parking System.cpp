class ParkingSystem {
public:
    int parking[3];
    ParkingSystem(int big, int medium, int small) {
        parking[0] = big;
        parking[1] = medium;
        parking[2] = small;
    }
    
    bool addCar(int carType) {
        if(carType==1 && parking[0]>0) {
            parking[0]--;
            return true;
        }
        else if(carType==2 && parking[1]>0) {
            parking[1]--;
            return true;
        }
        else if(carType==3 && parking[2]>0) {
            parking[2]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
