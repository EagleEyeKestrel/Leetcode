//
//  main.cpp
//  解法2，参考zqy1018
//  解法1针对应该优先删除ab还是ba进行讨论
//  这里讨论x>=y之后，直接贪心解决，优先删除ab，再看一遍删除ba
//  之前就尝试简单的贪心解决这个问题，能删ab/ba就删除。但发现有的时候在删除ab还是ba上会出错
//  讨论一下就可以了
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string ss, sss;
        int res = 0;
        if (x >= y) {
            for (char c: s) {
                if (c != 'b') ss.push_back(c);
                else {
                    if (ss.size() && ss.back() == 'a') {
                        res += x;
                        ss.pop_back();
                    } else ss.push_back('b');
                }
            }
            for (char c: ss) {
                if (c != 'a') sss.push_back(c);
                else {
                    if (sss.size() && sss.back() == 'b') {
                        res += y;
                        sss.pop_back();
                    } else sss.push_back('a');
                }
            }
        } else {
            for (char c: s) {
                if (c != 'a') ss.push_back(c);
                else {
                    if (ss.size() && ss.back() == 'b') {
                        res += y;
                        ss.pop_back();
                    } else ss.push_back('a');
                }
            }
            for (char c: ss) {
                if (c != 'b') sss.push_back(c);
                else {
                    if (sss.size() && sss.back() == 'a') {
                        res += x;
                        sss.pop_back();
                    } else sss.push_back('b');
                }
            }
        }
        return res;
    }
};
