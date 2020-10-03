//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class ParkingSystem {
public:
    int cnt[4], limit[4];
    ParkingSystem(int big, int medium, int small) {
        memset(cnt, 0, sizeof(cnt));
        limit[1] = big;
        limit[2] = medium;
        limit[3] = small;
    }
    
    bool addCar(int carType) {
        if(cnt[carType] < limit[carType]) {
            cnt[carType]++;
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
