//
//  main.cpp
//  O(N)的算法, cur记录到A[i]为止的子数组的所有或和。由于只有32位，所以每个cur大小不超过32
//  很妙的绝对O(N)的算法，但肯定是常数太大了过不了。。
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        unordered_set<int> res, cur;
        for(int i = 0; i < n; i++) {
            unordered_set<int> tmp;
            tmp.insert(A[i]);
            res.insert(A[i]);
            for(auto it = cur.begin(); it != cur.end(); it++) {
                int v = (*it) | A[i];
                tmp.insert(v);
                res.insert(v);
            }
            cur = tmp;
        }
        return res.size();
    }
};
