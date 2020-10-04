//
//  main.cpp
//  无脑的暴力 O(n^3)
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0, n = rating.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(rating[i] > rating[j] && rating[j] > rating[k] || rating[i] < rating[j] && rating[j] < rating[k]) res++;
                }
            }
        }
        return res;
    }
};
