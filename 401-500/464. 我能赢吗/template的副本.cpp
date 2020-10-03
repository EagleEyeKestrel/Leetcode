//
//  main.cpp
//  挺不错的一道题，能感受到一步一步去改善自己算法的过程
//  首先因为maxInt非常小，所以可以用状态压缩去表示已经使用过的数的状态。
//  对于一个人，只要知道used，就是他当前面临的状态。理论上可以由used算出left，方便起见状态里加了一个left。
//  每次对于一个可用的i，要么i比left大了，要么选完i之后另一个人输了，那我就赢了
//  但这样交上去会TLE。所以要加一个记忆化搜索，对于used存一下结果，因为used可能会多次遇到
//  但交上去仍然会WA，最后还有一个total比所有数加起来都大的用例，这里是算作false的，特判一下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    unordered_map<int, bool> m;
    bool dfs(int used, int maxInt, int left) {
        if(m.count(used)) return m[used];
        for(int i = 1; i <= maxInt; i++) {
            if(!((used >> i) & 1)) {
                int newused = used | (1 << i);
                if(left <= i || !dfs(newused, maxInt, left - i)) {
                    m[used] = true;
                    return true;
                }
            }
        }
        m[used] = false;
        return false;
    }
    bool canIWin(int maxInt, int total) {
        if(total > maxInt * (maxInt + 1) / 2) return false;
        return dfs(0, maxInt, total);
    }
};
