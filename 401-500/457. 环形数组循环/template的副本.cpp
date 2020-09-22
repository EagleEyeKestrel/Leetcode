//
//  main.cpp
//  用vis标记是否走到过，用nowcolor模拟染色
//  走到之前染过色的点说明是失败的
//  WA了一次，vis[now] = nowcolor要放在if里面。
//  因为如果是因为方向不符合的点，干脆就不应该到达，因为其他情况到达这个点是可以继续走的，说不定就成环了
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size(), nowcolor = 1;
        if(!n) return false;
        int vis[n];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int last = i, now = i;
                while(1) {
                    if(vis[now]) {
                        if(vis[now] == nowcolor && now != last) return true;
                        else break;
                    }
                    if(nums[now] * nums[last] > 0) {
                        vis[now] = nowcolor;
                        last = now;
                        now = ((now + nums[now] + n) % n + n) % n;
                    } else {
                        break;
                    }
                }
                nowcolor++;
            }
        }
        return false;
    }
};
