//
//  main.cpp
//  参考评论区的优化的O(n2)，设定一个封顶的mask，其实还是很容易撞到的
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res;
        int maxval = *max_element(A.begin(), A.end());
        int mask = 1;
        while(mask <= maxval) mask <<= 1;
        mask -= 1;
        for(int i = 0; i < A.size(); i++) {
            int val = A[i];
            res.insert(val);
            for(int j = i + 1; j < A.size() && val != mask; j++) {
                val = val | A[j];
                res.insert(val);
            }
        }
        return res.size();
    }
};
