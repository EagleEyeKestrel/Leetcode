//
//  main.cpp
//  我第一遍想的方法
//  对于一个位置i，其实就是去找在[i-max,i-min]范围内是否存在能达到的0
//  用reached数组存储所有reached的坐标
//  然后二分在reached里面寻找就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int> reached = { 0 };
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') continue;
            int l = max(0, i - maxJump), r = i - minJump;
            if (r < 0) continue;
            auto it1 = lower_bound(reached.begin(), reached.end(), l);
            auto it2 = upper_bound(reached.begin(), reached.end(), r);
            if (it1 != it2) reached.push_back(i);
        }
        return reached.back() == s.size() - 1;
    }
};
