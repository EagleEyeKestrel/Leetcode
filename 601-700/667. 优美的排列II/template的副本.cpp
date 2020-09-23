//
//  main.cpp
//  直接构造一个1, k+1, 2, k...   k+2, k+3...这样的排列即可
//  注意第一段的末尾和k+2的差一定不超过k
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int l = 1, r = k + 1;
        while(l < r) {
            res.push_back(l);
            res.push_back(r);
            l++;
            r--;
        }
        if(l == r) res.push_back(l);
        for(int i = k + 2; i <= n; i++) res.push_back(i);
        return res;
    }
};
