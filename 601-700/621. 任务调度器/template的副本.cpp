//
//  main.cpp
//  贪心，先考虑数量最多的任务，时间至少是这几个最多的任务的时间，也就是max里第一个数
//  如果剩余任务把最大任务之间的空隙插满了，就还需要在其他地方插
//  位置一定是有的，此时没有等待时间，结果就是任务的个数
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int l = tasks.size(), maxcnt = 0, maxtask = 0;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < tasks.size(); i++) {
            cnt[tasks[i] - 'A']++;
            maxcnt = max(maxcnt, cnt[tasks[i] - 'A']);
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == maxcnt) maxtask++;
        }
        return max((n + 1) * (maxcnt - 1) + maxtask, (int)tasks.size());
    }
};
