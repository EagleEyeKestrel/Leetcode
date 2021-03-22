//
//  main.cpp
//  感觉这是见过的题干最长的题了。。
//  其实说了这么多，意思很简单，每次就是要取某种订单里的最大/最小的一个
//  用两个堆就可以了
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> buy;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sell;
        int mod = 1e9 + 7, res = 0;
        for (auto &order: orders) {
            if (order[2]) {
                int left = order[1];
                while (left && !buy.empty() && buy.top().first >= order[0]) {
                    if (left >= buy.top().second) {
                        left -= buy.top().second;
                        buy.pop();
                    } else {
                        auto tmp = buy.top();
                        buy.pop();
                        tmp.second -= left;
                        left = 0;
                        buy.push(tmp);
                    }
                }
                if (left > 0) sell.push({ order[0], left });
            } else {
                int left = order[1];
                while (left && !sell.empty() && sell.top().first <= order[0]) {
                    if (left >= sell.top().second) {
                        left -= sell.top().second;
                        sell.pop();
                    } else {
                        auto tmp = sell.top();
                        sell.pop();
                        tmp.second -= left;
                        left = 0;
                        sell.push(tmp);
                    }
                }
                if (left > 0) buy.push({ order[0], left });
            }
        }
        while (!buy.empty()) res = (res + buy.top().second) % mod, buy.pop();
        while (!sell.empty()) res = (res + sell.top().second) % mod, sell.pop();
        return res;
    }
};
