//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int vis[2010];
        memset(vis, 0, sizeof(vis));
        for (int x: nums) vis[x] = 1;
        while (vis[original]) original <<= 1;
        return original;
    }
};