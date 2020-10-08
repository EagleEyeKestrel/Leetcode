//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int n = candies.size();
        int maxv = *(max_element(candies.begin(), candies.end()));
        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= maxv) {
                    res.push_back(true);
                } else{
                    res.push_back(false);
                }
            }
        return res;
    }
};
