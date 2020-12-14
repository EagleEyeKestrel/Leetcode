//
//  main.cpp
//  看上去很难很复杂很吓人
//  其实想一想，两只相遇的蚂蚁都吊头折返，和两只都不吊头笔直往前走，不是没区别吗？
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(int x: left) res = max(res, x);
        for(int x: right) res = max(res, n - x);
        return res;
    }
};
