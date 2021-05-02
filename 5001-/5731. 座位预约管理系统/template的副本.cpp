//
//  main.cpp
//  用集合维护座位是否被占用即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class SeatManager {
public:
    set<int> s;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) s.insert(i);
    }
    
    int reserve() {
        auto it = s.begin();
        int res = *it;
        s.erase(s.begin());
        return res;
    }
    
    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
