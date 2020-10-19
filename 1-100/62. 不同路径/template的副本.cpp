//
//  main.cpp
//  可以dp，当然也可以用组合数，在m + n - 2步里选n - 1步向下
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = m + n - 2;
        int b = n - 1;
        long long res = 1;
        //(m+n-2)!/(n-1)!(m-1)!
        for(int i = n; i <= m + n - 2; i++) {
            res = res * i / (i - n + 1);
        }
        return (int)res;
    }
};
