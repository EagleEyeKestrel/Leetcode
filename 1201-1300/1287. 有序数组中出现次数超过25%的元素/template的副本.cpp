//
//  main.cpp
//  直接看哪个元素能占到nn长度
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int nn = n / 4 + 1;
        for(int i = nn - 1; i < n; i++) {
            if(arr[i] == arr[i - nn + 1]) return arr[i];
        }
        return 0;
    }
};
