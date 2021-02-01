//
//  main.cpp
//  好题
//  首先想大概思路。s和t的字符组成一定要完全一样，所以排序
//  然后再想怎么排序，想到贪心处理，每次排序可以转化为若干次相邻元素的交换
//  比如84532到34852，先把3通过三次交换提到前面来，变成38452，再交换一次4和8变成34852
//  这样模拟贪心的过程是O(n2)的，超时
//  想一想如何优化，我们发现转化不了的情况是，在一次向前交换的过程中
//  交换s[i] s[i+1]，但实际上s[i]<s[i+1]，就不能通过排序交换到后面去
//  然后怎么处理我想了好久没想到。关键在于，字符串都是数字，只有10种
//  维护每个数字在s中所有位置，然后遍历t的每个元素，比如当前是num
//  检查所有比num小的数字，如果某个数字存在比当前g[num].front()更小的索引，
//  说明这个数字之后需要被交换到num后面去，这不可能
//  这种方法的话因为是从前往后，可以用queue[10]存索引。
//  这里就倒过来对称了一下，就用的vector，从后往前遍历，一样的
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    bool isTransformable(string s, string t) {
        int n = s.size();
        vector<int> g[10];
        string ss = s, tt = t;
        sort(ss.begin(), ss.end());
        sort(tt.begin(), tt.end());
        if (ss != tt) return false;
        for (int i = 0; i < n; i++) {
            g[s[i] - '0'].push_back(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            int num = t[i] - '0';
            for (int j = num + 1; j < 10; j++) {
                if (!g[j].empty() && g[j].back() > g[num].back()){
                    return false;
                }
            }
            g[num].pop_back();
        }
        return true;
    }
};
