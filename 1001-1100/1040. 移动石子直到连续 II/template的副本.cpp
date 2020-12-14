//
//  main.cpp
//  挺难的，第一次没想到
//  两部分问题，一部分求最小值，一部分求最大值
//  最大值解起来比较简单。排序之后，gaps表示从头到尾一共有几个空格，firstOmit表示第一次移动会跳过几个空格
//  第一次不可避免的会忽略掉firstOmit个空格，但之后我们可以每次都尽可能放在靠近端点的空格，这样每次空格会减少一个
//  最小值，我们用滑动窗口找到n大小范围内，里面最多有maxNum个数。结果就是拿区间外面的数去填n - maxNum个空格
//  但有个反例，比如1,2,3,4,7，由于不能7直接移动到5，所以需要两次。
//  这种情况是窗口里有连续n-1个数字，单独判定一下。只要少于n-1就不会出现这种问题
//  比如1,2,3,4,7,9，9就可以先移到6，7到5
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size(), l = 0;
        int gaps = stones[n - 1] - stones[0] + 1 - n;
        int firstOmit = min(stones[1] - stones[0], stones[n - 1] - stones[n - 2]) - 1;
        int maxMoves = gaps - firstOmit;

        int maxNum = 0;
        for (int r = 0; r < n; r++) {
            while (stones[r] - stones[l] + 1 > n) {
                l++;
            }
            if (r - l + 1 == n - 1 && stones[r] - stones[l] + 1 == n - 1) {
                maxNum = max(n - 2, maxNum);
            } else {
                maxNum = max(maxNum, r - l + 1);
            }
        }
        int minMoves = n - maxNum;
        return {minMoves, maxMoves};
    }
};
