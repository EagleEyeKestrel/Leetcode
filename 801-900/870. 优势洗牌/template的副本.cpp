//
//  main.cpp
//  经典的田忌赛马问题，贪心
//  如果A里找不到大于的，索性拿个最小的
//  找得到，就找大于B[i]里面的最小的
//  使用multiset，非常方便
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        multiset<int> s(A.begin(), A.end());
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(B[i] >= *(s.rbegin())) {
                res.push_back(*(s.begin()));
                s.erase(s.begin());
            } else {
                auto it = s.upper_bound(B[i]);
                res.push_back(*it);
                s.erase(it);
            }
        }
        return res;
    }
};
