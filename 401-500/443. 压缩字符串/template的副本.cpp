//
//  main.cpp
//  比较简单的双指针
//  但是自己做WA了一次，遇到一个没想到的问题
//  我比较习惯用一个tmp表示当前连续字符的数量
//  但遇到比如x,7,7,2,2,2 在原地修改的时候
//  当走到第一个2的时候，之前的数组已经被改成了x,7,2，所以这个时候tmp会拿到错误的值
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0, j = 0, tmp = 0;
        while (i < n) {
            char c = chars[i];
            int start = i;
            while (i < n && chars[i] == c) i++;
            chars[j++] = c;
            int l = i - start;
            if (l == 1) continue;
            auto s = to_string(l);
            for (char w: s) chars[j++] = w;
        }
        return j;
    }
};
