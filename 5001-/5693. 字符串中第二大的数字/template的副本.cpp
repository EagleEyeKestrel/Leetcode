//
//  main.cpp
//  要注意，用rbegin迭代器的话，想找到第二大的元素，应该++而非--
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int secondHighest(string s) {
        set<int> se;
        for (char c: s) {
            if (isdigit(c)) se.insert(c - '0');
        }
        if (se.size() <= 1) return -1;
        auto it = se.rbegin();
        it++;
        return *it;
    }
};
