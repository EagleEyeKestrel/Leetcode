//
//  main.cpp
//  写85的时候发现84这个经典问题很不熟练，复习了一下，感觉理解的更为透彻了
//  对于一个矩形，我们要求这个矩形高度限制下，往左右延伸，形成矩形的最大面积
//  肯定形成的这个矩形的右边和左边都是第一个比它小的高度
//  自然想到用一个递增栈。当一个列被弹出
//  他的下面是左边第一个比他小的高度，弹出的这个i是右边第一个比他小的高度，所以就可以了
//  但还有两个问题需要解决，一个是结束后栈内还有元素，这些元素说明右边没有比他小的了，所以还需要额外算一下
//  另外，如果高度相等，这里也选择弹出。
//  严格来讲，这里的策略是，弹出的列的下面是高度严格小于他的第一个，弹出者第i列是他右边第一个小于等于他的
//  所以一个矩形最矮高度如果有多个，我们在算的时候是以最右边的一列为基准计算
//  比如对于高度4，3，5，6，3，7，要算这个长6高3的矩形，我们只有在弹出第二个3的时候才会算
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int n = heights.size(), res = 0;
        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && heights[i] <= heights[s.top()]) {
                int tmp = heights[s.top()];
                s.pop();
                res = max(res, tmp * (i - s.top() - 1));
            }
            s.push(i);
        }
        while (s.top() != -1) {
            int tmp = s.top();
            s.pop();
            res = max(res, heights[tmp] * (n - 1 - s.top()));
        }
        return res;
    }
};
