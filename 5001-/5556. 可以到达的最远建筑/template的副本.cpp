//
//  main.cpp
//  可以发现策略很容易想，最大的间隔用梯子，小的用bricks
//  开始一直想边遍历边做，一直没想到什么nlgn的方法，感觉如果能够一次性知道所有的间隔就好了
//  所以二分就应运而生，太方便了，对于每个索引我们可以用O(n)验证能不能走到
//  另外，看了JOHNKRAM的解法，边遍历边做也很简单
//  multiset里只保留ladders个最大的数。往set里插入数，如果插了之后size>ladders，那bricks就减去*set.begin()，因为这个间隔必须用bricks
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int check(int mid, vector<int>& heights, int bricks, int ladders) {
        int gaps[1000010];
        int now = 1, sum = 0;
        for(int i = 1; i <= mid; i++) {
            if(heights[i] > heights[i - 1]) {
                gaps[now++] = heights[i] - heights[i - 1];
            }
        }
        sort(gaps + 1, gaps + now);
        for(int i = 1; i <= now - 1 - ladders; i++) {
            sum += gaps[i];
        }
        return sum <= bricks;
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(), res = 0;
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(check(mid, heights, bricks, ladders)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
