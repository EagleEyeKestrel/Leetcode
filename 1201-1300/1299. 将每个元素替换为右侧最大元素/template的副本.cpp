//
//  main.cpp
//  最优解法不需要再新建一个数组了，直接从右向左遍历得到，维护当前右边的最大值即可
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size(), nowmax = arr.back();
        arr[n - 1] = -1;
        for(int i = n - 2; i >= 0; i--) {
            int tmp = arr[i];
            arr[i] = nowmax;
            nowmax = max(nowmax, tmp);
        }
        return arr;
    }
};
