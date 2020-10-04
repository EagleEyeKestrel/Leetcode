//
//  main.cpp
//  用个简单的dp就可以变成O(n^2)，bigger/smaller[i]表示i之前比i更大/小的rating个数
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0, n = rating.size();
        int smaller[n], bigger[n];
        memset(smaller, 0, sizeof(smaller));
        memset(bigger, 0, sizeof(bigger));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(rating[j] < rating[i]) {
                    res += smaller[j];
                    smaller[i]++;
                }
                if(rating[j] > rating[i]) {
                    res += bigger[j];
                    bigger[i]++;
                }
            }
        }
        return res;
    }
};
