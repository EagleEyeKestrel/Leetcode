//
//  main.cpp
//  先全部变成012
//  讨论alice先拿1还是2.比方说先拿1，先不考虑0，那序列必然是1121212...，然后0可以插在任意位置不影响结果。所以看的就是1121212... 000的最长序列能保持多少。如果这个方式可以赢，就return 1 。同样再讨论先拿2的情况，是一样的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int a = 0, b = 0, c = 0;
        for (int x: stones) {
            if (x % 3 == 1) a++;
            if (x % 3 == 2) b++;
            if (x % 3 == 0) c++;
        }
        if (a > 0) {
            int sum = 2 * min(a - 1, b) + 1 + c;
            if (a - 1 > b) sum++;
            if (sum % 2 == 1 && sum != a + b + c) return 1;
        }
        if (b > 0) {
            int sum = 2 * min(a, b - 1) + 1 + c;
            if (b - 1 > a) sum++;
            if (sum % 2 == 1 && sum != a + b + c) return 1;
        }
        return 0;
        
    }
};
