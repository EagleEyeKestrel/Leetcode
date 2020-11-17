//
//  main.cpp
//  看了一下树状数组能做，就直接树状数组先过了
//  这样对每个点的查询都是logn的
//  但似乎看评论大多数都是树状数组做的，早知道这次就参加了啊
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int c[1000010];
    int mod = 1e9 + 7;
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int i) {
        while(i <= 1e5) {
            c[i]++;
            i += lowbit(i);
        }
    }
    int getsum(int i) {
        int res = 0;
        while(i) {
            res += c[i];
            i -= lowbit(i);
        }
        return res;
    }
    int createSortedArray(vector<int>& instructions) {
        memset(c, 0, sizeof(c));
        int res = 0;
        for(int i = 0; i < instructions.size(); i++) {
            add(instructions[i]);
            res = (res + min(getsum(instructions[i] - 1), getsum(1e5) - getsum(instructions[i]))) % mod;
        }
        return res;
    }
};
