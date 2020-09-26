//
//  main.cpp
//  从n到1每次构造一位就可以了，每一位至多两步
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for(int i = n; i >= 1; i--) {
            int index = -1;
            for(int j = 0; j < n; j++) {
                if(arr[j] == i) {
                    index = j;
                    break;
                }
            }
            if(index != i - 1) {
                res.push_back(index + 1);
                res.push_back(i);
                reverse(arr.begin(), arr.begin() + index + 1);
                reverse(arr.begin(), arr.begin() + i);
            }
        }
        return res;
    }
};
