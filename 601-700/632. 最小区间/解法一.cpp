//
//  main.cpp
//  自己写的，写了挺久。。第二次了
//  主要先排雷一个错误思路：穷举第一个区间的每一个数，比如说是x，然后接下来在每个区间找离x最近的元素加入区间，看每次这样得到的最小区间
//  反例：[[1],[88],[-1,87]]，这样会得到[-1,88]
//  这里的思路，弄n个指针，指向当前每个数组的最小元素，算极差，然后每次淘汰最小的元素，加入淘汰元素后面的那个元素。堆维护当前n个元素的最小值，maxv维护堆里的最大值
//  一开始我还弄了个flag，设置当有一个数组到达末尾，minv就停留在这个数组末尾的元素而非堆顶，这样可以把每个数组最后一个元素从堆里弹出去，退出条件就是q.empty()
//  但其实有一个数组达到末尾就可以直接break，因为之后的minv不变，而maxv只会更大
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size(), mind = INT_MAX, maxv = INT_MIN, flag = 0;
        int p[n];
        memset(p, 0, sizeof(p));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            q.push({ nums[i][0], i });
            maxv = max(maxv, nums[i][0]);
        }
        while (!q.empty()) {
            auto tmp = q.top();
            q.pop();
            int tmpmin = tmp.first;
            if (maxv - tmpmin < mind) {
                mind = maxv - tmpmin;
                res = { tmpmin, maxv };
            }
            p[tmp.second]++;
            if (p[tmp.second] < nums[tmp.second].size()) {
                q.push({ nums[tmp.second][p[tmp.second]], tmp.second });
                maxv = max(maxv, nums[tmp.second][p[tmp.second]]);
            } else {
                break;
            }
        }
        return res;
    }
};
