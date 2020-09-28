//
//  main.cpp
//  排序其实也是很不错的一个解法。当s1 == s2时，就可以成一个新块。这和I是相通的
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(), v.end());
        long long s1 = 0, s2 = 0, res = 0;
        for(int i = 0; i < v.size(); i++) {
            s1 += arr[i];
            s2 += v[i];
            if(s1 == s2) res++;
        }
        return (int)res;
    }
};
