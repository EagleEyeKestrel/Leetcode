//
//  main.cpp
//  刚写完反应过来，其实就是n-1啊
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while(n > 1) {
            if (n % 2) {
                res += n / 2;
                n = n / 2 + 1;
            } else {
                res += n / 2;
                n = n / 2;
            }
        }
        return res;
    }
};
