//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        double sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i < n * 0.05 || i >= n * 0.95) continue;
            sum += arr[i];
            cnt++;
        }
        return sum / cnt;
    }
};
