//
//  main.cpp
//  从刚刚nlogn的做法可以看出，其实我们只需要求出i后面的递增序列中，有几个比h[i]小
//  而这些元素本来就会被弹出来。所以每次弹出的时候++即可
//  最后判断一下还有没有更高的。如果有，再+1.即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[i] > heights[s.top()]) {
                s.pop();
                res[i]++;
            }
            if (!s.empty()) res[i]++;
            s.push(i);
        }
        return res;
    }
};
