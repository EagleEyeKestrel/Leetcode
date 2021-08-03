//
//  main.cpp
//  比赛时的做法，显然是经典的单调栈
//  对于i右侧的一个递增序列，显然他只能看到所有比自己矮的人，以及第一个比自己高的人
//  当时直接二分找到了第一个比自己高的人然后直接算出res[i]的结果，也可以
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        vector<int> v, val;
        for (int i = n - 1; i >= 0; i--) {
            int id = upper_bound(val.rbegin(), val.rend(), heights[i]) - val.rbegin();
            if (id == val.size() || id == val.size() - 1) res[i] = val.size();
            else res[i] = id + 1;
            while (!v.empty() && heights[i] > heights[v.back()]) v.pop_back(), val.pop_back();
            v.push_back(i), val.push_back(heights[i]);
        }
        return res;
    }
};
