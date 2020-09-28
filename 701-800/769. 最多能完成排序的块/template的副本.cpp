//
//  main.cpp
//  第一问还是简单的，当和等于i * (i + 1) / 2时，只可能是前i + 1个数刚好是0 到 i
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), res = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == (i + 1) * i / 2) res++;
        }
        return res;
    }
};
