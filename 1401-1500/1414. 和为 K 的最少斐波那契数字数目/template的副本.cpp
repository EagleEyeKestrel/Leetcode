//
//  main.cpp
//  要知道1e9以下的斐波那契数其实很少，就几十个
//  然后显然也是可贪心的，因为小的数之和就等于某个大数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibos = {1, 1};
        while(1) {
            int nextv = fibos.back() + fibos[fibos.size() - 2];
            if(nextv > 1e9) break;
            fibos.push_back(nextv);
        }
        int res = 0;
        for(int i = fibos.size() - 1; i >= 0; i--) {
            while(k >= fibos[i]) {
                k -= fibos[i];
                res++;
            }
        }
        return res;
    }
};
