//
//  main.cpp
//  没什么好说的，周赛第三题出了个模拟
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    void f(int &now, int &res, int need, int cap) {
        if (now >= need) {
            now -= need;
        } else {
            now = cap;
            res++;
            now -= need;
        }
    }
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size(), res = 0, l = 0, r = n - 1;
        int now1 = capacityA, now2 = capacityB;
        while (1) {
            if (l > r) break;
            if (l == r) {
                if (now1 >= now2) f(now1, res, plants[l], capacityA);
                else f(now2, res, plants[l], capacityB);
                break;
            }
            f(now1, res, plants[l], capacityA);
            f(now2, res, plants[r], capacityB);
            l++, r--;
        }
        return res;
    }
};
