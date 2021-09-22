//
//  main.cpp
//  这道题其实最主要的是要看清题目。。nextvisit一定是<=i的，如果是>i的好像就没什么办法了
//  用s[i]表示第一次到达i的次数，用j表示nextvisit[i-1]，从i-1到i的过程大概是
//  第一次到达i-1，会跑到j。然后从j再到i-1，此时这部分的内容一定都是访问过偶数次。所以所有的步骤是
//  s[i-1],走1步到j，s[i-1]-s[j]是到达i-1之后到j需要的次数。再加1是从i-1到i
//  另外，还有个样例刚好卡1e9+6，所以一定要+mod-1
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int mod = 1e9 + 7, n = nextVisit.size();
        int s[n];
        s[0] = 1;
        s[1] = 3;
        for (int i = 2; i < n; i++) {
            s[i] = (s[i - 1] + 1) % mod;
            int j = nextVisit[i - 1];
            int add = (s[i - 1] - s[j] + mod) % mod;
            s[i] = (s[i] + add + 1) % mod;
        }
        return (s[n - 1] + mod - 1) % mod;
    }
};
