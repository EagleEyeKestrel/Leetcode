//
//  main.cpp
//  比较简单，用up[i],down[i]表示从每个点奇数/偶数起跳能否到达终点
//  用一个pos维护每个值最靠近的索引，然后用集合s记录右边的所有值，这样可以log时间找到下一个跳到达的值，从而可以在up和down之间，从后往前进行更新
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size(), res = 1;
        int up[n], down[n];
        int pos[100010];
        up[n - 1] = 1, down[n - 1] = 1;
        pos[arr[n - 1]] = n - 1;
        set<int> s = {arr[n - 1]};
        for (int i = n - 2; i >= 0; i--) {
            auto it = s.lower_bound(arr[i]);
            if (it == s.end()) {
                up[i] = 0;
            } else {
                up[i] = down[pos[*it]];
            }
            it = s.upper_bound(arr[i]);
            if (it == s.begin()) {
                down[i] = 0;
            } else {
                it--;
                down[i] = up[pos[*it]];
            }
            s.insert(arr[i]);
            pos[arr[i]] = i;
            if (up[i]) res++;
        }
        return res;
    }
};
