//
//  main.cpp
//  卡了一段时间，还TLE了几次
//  这次学会了计算贪心条件：假设alice选择下标i1,i2... bob选择j1,j2..
//  如果i1 j1交换可以获得更优解, 说明a[i1]-b[j1] < a[j1]-b[i1]
//  即a[i1]+b[i1]<a[j1]+b[j1]，说明优先要取a[i]+b[i]最大的，两边轮流取
//
//  另外，lambda函数里加上& 就是传引用。。否则就是传复制了，因为这个事情TLE了两次，但也算学到了新的东西
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        int stones[n];
        for(int i = 0; i < n; i++) stones[i] = i;
        sort(stones, stones + n, [&aliceValues, &bobValues](int a, int b) {
            return aliceValues[a] + bobValues[a] > aliceValues[b] + bobValues[b];
        });
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) {
            if (i % 2) {
                sum2 += bobValues[stones[i]];
            } else {
                sum1 += aliceValues[stones[i]];
            }
        }
        if (sum1 > sum2) return 1;
        if (sum1 < sum2) return -1;
        return 0;
    }
};
