//
//  main.cpp
//  题目说的也不太清楚。。
//  贪心，每个人依次否决对面剩余的第一个人。直到某一方没人为止
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    string predictPartyVictory(string senate) {
        int rs[10010], ds[10010];
        int i = 0, j = 0, n = senate.size();
        for(int k = 0; k < n; k++) {
            if(senate[k] == 'R') {
                rs[i++] = k;
            } else {
                ds[j++] = k;
            }
        }
        int ii = 0, jj = 0;
        while(ii < i && jj < j) {
            if(rs[ii] < ds[jj]) {
                rs[i++] = rs[ii] + n;
            } else{
                ds[j++] = ds[jj] + n;
            }
            ii++;
            jj++;
        }
        return ii == i ? "Dire" : "Radiant";
    }
};
