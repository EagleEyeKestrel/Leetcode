//
//  main.cpp
//  其实就是找下一个排列
//  偷懒的话可以用next_permutation函数秒
//  普通方法的话，先找到最后最长的连续降序列，比如说是8531，然后8的前面比如是4
//  48531下一个排列的话，在降序列中找到比4大的最小的数，换成58431
//  然后把5后的内容排序，变成51348，就是答案。判断一下是否越界
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        string s = to_string(n);
        int l = s.size(), id = -1;
        for (int i = l - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                id = i;
                break;
            }
        }
        if (id == -1) return -1;
        for (int i = l - 1; i > id; i--) {
            if (s[id] < s[i]) {
                swap(s[i], s[id]);
                break;
            }
        }
        sort(s.begin() + id + 1, s.end());
        long newnum = stol(s);
        if (newnum > INT_MAX) return -1;
        return newnum;
    }
};
