//
//  main.cpp
//  一次遍历即可。第一次没能想到
//  0跑到i发现和第一次<0，那说明0到i作为起点都不行。至少得i+1
//  显然至少要sum >= 0才能跑一圈。而且sum >= 0肯定能跑一圈
//  假设最后满足题意的起点是B，B之前是A，B的和大于等于-A，所以从B出发一定行
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), tmp = 0, sum = 0, res = 0;
        for(int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
            tmp += gas[i] - cost[i];
            if(tmp < 0) {
                res = i + 1;
                tmp = 0;
            }
        }
        return sum < 0 ? -1 : res;
    }
};
