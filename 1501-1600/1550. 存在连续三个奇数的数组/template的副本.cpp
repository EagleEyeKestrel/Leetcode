//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 2; i < arr.size(); i++) {
            if(arr[i] % 2 && arr[i - 1] % 2 && arr[i - 2] % 2) return true;
        }
        return false;
    }
};
