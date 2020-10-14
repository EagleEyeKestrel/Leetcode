//
//  main.cpp
//  差分的模版
//  用a标记，出生一个人+1，死一个人-1，最后累加的前缀和就是这个年份生存的人数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int a[2030];
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        memset(a, 0, sizeof(a));
        int n = birth.size(), resv = 0, resyear = 0;
        for(int i = 0; i < n; i++) {
            a[birth[i]]++;
            a[death[i] + 1]--;
        }
        for(int i = 1; i < 2030; i++) {
            a[i] = a[i] + a[i - 1];
            if(a[i] > resv) {
                resv = a[i];
                resyear = i;
            }
        }
        return resyear;
    }
};
