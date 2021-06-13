//
//  main.cpp
//  第三题反而比第二题更简单
//  首先产生target 得把triplets中含有比v更大的项扔了
//  然后看剩下的取最大值是不是target就行了。因为如果不是，最大值一定凑不到target
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<vector<int>> t;
        for (auto &v: triplets) {
            if (v[0] > target[0] || v[1] > target[1] || v[2] > target[2]) continue;
            t.push_back(v);
        }
        vector<int> res = { 0, 0, 0 };
        for (auto &v: t) {
            res[0] = max(res[0], v[0]);
            res[1] = max(res[1], v[1]);
            res[2] = max(res[2], v[2]);
        }
        return res[0] == target[0] && res[1] == target[1] && res[2] == target[2];
    }
};
