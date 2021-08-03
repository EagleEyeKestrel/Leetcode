//
//  main.cpp
//  根据正负，找到第一个小于/大于x的字符，在其之前插入
//  注意要加等号
//  但不知道为什么这么慢。。难道是insert太慢了？
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0] != '-') {
            int id = 0;
            while (id < n.size() && n[id] >= x + '0') id++;
            n.insert(n.begin() + id, x + '0');
        } else {
            int id = 1;
            while (id < n.size() && n[id] <= x + '0') id++;
            n.insert(n.begin() + id, x + '0');
        }
        return n;
    }
};
