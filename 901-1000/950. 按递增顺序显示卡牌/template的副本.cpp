//
//  main.cpp
//  排序之后，对于空位，每隔一个放一个就行了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size(), flag = 1, i = 0, now = 0;
        sort(deck.begin(), deck.end());
        vector<int> res(n, 0);
        while(now < n) {
            if(res[i]) {
                i = (i + 1) % n;
                continue;
            }
            if(flag) {
                res[i] = deck[now++];
                if(now == n) break;
            }
            flag = !flag;
            i = (i + 1) % n;
        }
        return res;
    }
};
