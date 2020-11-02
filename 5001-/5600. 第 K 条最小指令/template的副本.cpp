//
//  main.cpp
//  主要是组合数的处理，来判断第一位是什么
//  有两个坑，一个是c[0][0]要等于1
//  另外一个，c[x+y-1][x]第二位要是x而不能是y-1，比如y=0的情况
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int c[32][32];
    string f(int x, int y, int k) {
        if(!x && !y) return "";
        if(y && k <= c[x + y - 1][x]) return "H" + f(x, y - 1, k);
        return "V" + f(x - 1, y, k - c[x + y - 1][x]);
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        c[0][0] = 1;
        for(int i = 1; i <= 30; i++) {
            c[i][0] = 1;
            c[i][i] = 1;
        }
        for(int i = 2; i <= 30; i++) {
            for(int j = 1; j <= i; j++) {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
        return f(destination[0], destination[1], k);
    }
};
