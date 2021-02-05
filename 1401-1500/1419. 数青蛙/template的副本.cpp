//
//  main.cpp
//  我的做法，先确保每个字符都是n/5个
//  然后确保每个croak的顺序一致
//  最后判断最少需要几只青蛙。有点类似于平衡括号串的处理，找最大的递归深度
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if (n % 5) return -1;
        int cnt[128] = { 0 };
        for (char c: croakOfFrogs) cnt[c]++;
        if (cnt['c'] != n / 5 || cnt['a'] != n / 5 || cnt['o'] != n / 5 || cnt['r'] != n / 5 || cnt['k'] != n / 5) return -1;
        vector<int> v[5];
        for (int i = 0; i < n; i++) {
            if (croakOfFrogs[i] == 'c') v[0].push_back(i);
            if (croakOfFrogs[i] == 'r') v[1].push_back(i);
            if (croakOfFrogs[i] == 'o') v[2].push_back(i);
            if (croakOfFrogs[i] == 'a') v[3].push_back(i);
            if (croakOfFrogs[i] == 'k') v[4].push_back(i);
        }
        for (int i = 0; i < n / 5; i++) {
            if (!(v[0][i] < v[1][i] && v[1][i] < v[2][i] && v[2][i] < v[3][i] && v[3][i] < v[4][i])) return -1;
        }
        int tmp = 0, res = 0;
        for (char c: croakOfFrogs) {
            if (c == 'c') tmp++;
            if (c == 'k') tmp--;
            res = max(res, tmp);
        }
        return res;
    }
};
