//
//  main.cpp
//  很好的题，没有想到
//  把第二个规则，拆成两部分。从左往右看， 如果rating[i]>rating[i-1]，那么l[i]>l[i-1]（用l表示糖的个数）
//  从右往左看，如果rating[i]>rating[i+1]，那么r[i]>r[i+1]
//  每个人拿的糖应该是max(l[i], r[i])
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int l[n];
        for (int i = 0; i < n; i++) {
            if (i && ratings[i] > ratings[i - 1]) l[i] = l[i - 1] + 1;
            else l[i] = 1;
        }
        int r = 1, res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) r++;
            else r = 1;
            res += max(r, l[i]);
        }
        return res;
    }
};
