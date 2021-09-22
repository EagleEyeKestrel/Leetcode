//
//  main.cpp
//
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> s;
        for (int i = 1; i <= n; i++) s.insert(i * i);
        int res = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                if (s.count(a * a + b * b)) res++;
            }
        }
        return res;
    }
};
