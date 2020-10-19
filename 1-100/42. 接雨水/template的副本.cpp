//
//  main.cpp
//  很经典的题，对于每一个点，他能放的水的高度应该是左边最大高和右边最大高的最小值，设为h
//  对每个点，加上h和自己高度的落差即可
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        if(!n) return 0;
        int l[n], r[n];
        l[0] = 0;
        r[n - 1] = 0;
        for(int i = 1; i < n; i++) l[i] = max(l[i - 1], height[i - 1]);
        for(int i = n - 2; i >= 0; i--) r[i] = max(r[i + 1], height[i + 1]);
        for(int i = 0; i < n; i++) {
            int h = min(l[i], r[i]);
            if(h > height[i]) res += h - height[i];
        }
        return res;
    }
};
