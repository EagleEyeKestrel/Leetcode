//
//  main.cpp
//  是个数学题。根据猪的死亡情况，每头猪有s种不同的死亡时间，那么一共有s^x个状态
//  每个状态对应一个桶，所以就是log s(buckets)
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int s = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(s));
    }
};
