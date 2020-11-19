//
//  main.cpp
//  这是我认为比较容易想的一个办法，用一个map存某个点之前来的步数大小的集合，用这个map去更新可以到达的新的点
//  但是会有比较多次重复操作，常数较大。AC还是比较轻松的
//  看了以前的解答，同样用m，但是穷举思路不是按nows穷举，是穷举之前的j，甚至可以更快
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        unordered_map<int, unordered_set<int>> m;
        m[1].insert(1);
        unordered_set<int> s(stones.begin(), stones.end());
        for(int i = 1; i < n; i++) {
            unordered_set<int> nows = m[stones[i]];
            if(nows.empty()) continue;
            for(auto it = nows.begin(); it != nows.end(); it++) {
                int step = *it;
                if(s.count(step + stones[i])) {
                    m[step + stones[i]].insert(step);
                }
                if(s.count(step + 1 + stones[i])) {
                    m[step + 1 + stones[i]].insert(step + 1);
                }
                if(s.count(step - 1 + stones[i])) {
                    m[step - 1 + stones[i]].insert(step - 1);
                }
            }

        }
        return !m[stones.back()].empty();
    }
};
