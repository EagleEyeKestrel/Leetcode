//
//  main.cpp
//  没想到。知道要贪心，但是不会贪。还要加油呀
//  对于一个数，有两种去路，要么跟在之前某个序列之后，要么自己新起一个序列。
//  对于num,能跟优先跟。假如和num组成序列的元素以另一种形式存在，之后也能在这个序列里跟在后面，不影响。
//  need是表示num当前可以跟在几个顺子后面
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, need;
        for(int num: nums) cnt[num]++;
        for(int num: nums) {
            if(cnt[num]) {
                if(need[num] > 0) {
                    need[num]--;
                    need[num + 1]++;
                    cnt[num]--;
                } else if(cnt[num + 1] > 0 && cnt[num + 2] > 0) {
                    cnt[num]--;
                    cnt[num + 1]--;
                    cnt[num + 2]--;
                    need[num + 3]++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
