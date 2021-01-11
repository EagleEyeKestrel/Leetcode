//
//  main.cpp
//  年龄计数然后穷举就可以了
//  不要被双指针束缚了，这里年龄都很小，所以直接穷举年龄即可
//  另外循环的顺序不要反了，这里是a给b发送请求
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size(), res = 0;
        int cnt[121];
        memset(cnt, 0, sizeof(cnt));
        for (int age: ages) cnt[age]++;
        for (int a = 1; a <= 120; a++) {
            for (int b = 1; b <= a; b++) {
                if (b <= 0.5 * a + 7 || b > 100 && a < 100) continue;
                if (a == b) res += cnt[a] * (cnt[a] - 1);
                else res += cnt[a] * cnt[b];
            }
        }
        return res;
    }
};
