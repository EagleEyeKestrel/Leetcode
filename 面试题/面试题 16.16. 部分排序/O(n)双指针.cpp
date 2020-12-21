//
//  main.cpp
//  注释写了l和r的等价条件。比如求l，求的是第一个i，使得i右边的数的最小值，小于array[i]，所以i必须要排走
//  这个过程可以从右往左遍历得到。求r同理，这个代码可以跑的比较快
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        //l: first i s.t. rmin[i] < array[i]
        //r: last i s.t. lmax[i] > array[i]
        int l = -1, r = -1, n = array.size();
        int lmax = INT_MIN, rmin = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (lmax > array[i]) r = i;
            lmax = max(lmax, array[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (rmin < array[i]) l = i;
            rmin = min(rmin, array[i]);
        }
        return {l, r};
    }
};
