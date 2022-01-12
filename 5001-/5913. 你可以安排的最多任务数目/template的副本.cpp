//
//  main.cpp
//  二分check题，但不是那么明显。
//  检查num个任务时，肯定是选最小的num个任务，分给最大的num个worker
//  关键在于贪心策略。从大到小检查任务，如果有人比任务大，那肯定用它（用最大的即可
//  如果没有，那就使用比t - strength大的 最小的worker
//  直接贪心是不对的，因为一个人可以选择不工作，而贡献出自己的药丸
//  还有nlogn的算法。就是在check内，用单调队列维护 对于当前工作 吃了药丸能工作的所有worker
//  然后每次从两头更新即可
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int m, n;
    int check(int num, vector<int> &tasks, vector<int> &workers, int pills, int strength) {
        multiset<int> se;
        for (int i = n - 1; i >= n - num; i--) se.insert(workers[i]);
        int now = 0;
        for (int i = num - 1; i >= 0; i--) {
            int t = tasks[i];
            if (*(se.rbegin()) >= t) {
                se.erase(--se.end());
            } else {
                if (now == pills) return 0;
                auto it = se.lower_bound(t - strength);
                if (it == se.end()) return 0;
                se.erase(it);
                now++;
            }
        }
        return 1;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        m = tasks.size(), n = workers.size();
        int l = 0, r = min(m, n);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid, tasks, workers, pills, strength)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
