//
//  main.cpp
//  队列的模拟用queue或者deque都可以简单模拟
//  主要是退出条件怎么判断？我统计了1和0的个数，如果当前sandwich没有对应的人了，就退出
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt[2];
        memset(cnt, 0, sizeof(cnt));
        for (int student: students) {
            cnt[student]++;
        }
        deque<int> q(students.begin(), students.end());
        int i = 0, n = sandwiches.size();
        while (!q.empty()) {
            if (!cnt[sandwiches[i]]) return n - i;
            while (q.front() != sandwiches[i]) {
                q.push_back(q.front());
                q.pop_front();
            }
            cnt[q.front()]--;
            q.pop_front();
            i++;
        }
        return 0;
    }
};
