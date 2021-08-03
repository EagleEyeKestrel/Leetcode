//
//  main.cpp
//  这种不能连续做同一个的问题，显然瓶颈在于时间最长的那一个
//  如果时间最长的比其他所有的加起来都长，那么最多只能做到其他所有的*2+1个
//  否则，那一定可以都做完
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int n = milestones.size();
        if (n == 1) return 1;
        sort(milestones.begin(), milestones.end());
        long long s1 = 0;
        for (int i = 0; i < n - 1; i++) s1 += milestones[i];
        if (s1 < milestones[n - 1]) {
            return 2 * s1 + 1;
        }
        return s1 + milestones[n - 1];
    }
};
