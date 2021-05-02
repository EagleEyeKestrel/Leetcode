//
//  main.cpp
//  用next_permutation求出下面k个排列，省的造轮子了
//  然后要求从num到target最少交换次数，直接贪心一位位模拟
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;
        for (int i = 0; i < k; i++) {
            next_permutation(target.begin(), target.end());
        }
        int n = num.size(), res = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] == target[i]) continue;
            int j = i;
            while (num[j] != target[i]) j++;
            for (int k = j - 1; k >= i; k--) {
                swap(num[k], num[k + 1]);
            }
            res += j - i;
        }
        return res;
    }
};
