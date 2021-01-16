//
//  main.cpp
//  排序之后比较，要么是全小于等于，要么是全大于等于
//  因为倘若是满足全小于等于，那一定是排序之后，是最优情况
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int flag = 1;
        for (int i = 0; i < s1.size(); i++) {
            if  (s1[i] > s2[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) return true;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i]) {
                flag = 1;
                break;
            }
        }
        return flag == 0;
    }
};
