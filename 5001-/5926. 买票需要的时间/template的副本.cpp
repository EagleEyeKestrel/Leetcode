//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0, n = tickets.size();
        for (int i = 0; i < k; i++) {
            res += min(tickets[i], tickets[k]);
        }
        res += tickets[k];
        for (int i = k + 1; i < n; i++) {
            res += min(tickets[i], tickets[k] - 1);
        }
        return res;
    }
};
