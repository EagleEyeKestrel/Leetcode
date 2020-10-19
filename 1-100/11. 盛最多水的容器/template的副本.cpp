//
//  main.cpp
//  很经典的题，实际上就是双指针
//  当对于一个(l,r)，较小的那个在(l,r)内已经不可能再形成更大的体积了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, n = height.size();
        int l = 0, r = n - 1;
        while(l < r) {
            res = max(res, min(height[l], height[r]) * (r - l));
            if(height[l] <= height[r]) l++;
            else r--;
        }
        return res;
    }
};
