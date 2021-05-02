//
//  main.cpp
//  比较直观的想法：离线排序queries，从小到大处理minsize
//  关键是要维护一个满足size>=minsize的房间集合，这里用了个堆，或者也可以把rooms排序处理，反正就是每次淘汰掉不满足大小的房间。
//  然后这里用了个集合存所有满足的房间集合，二分找到离prefer最近的编号。
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    struct room {
        int id, sz;
        bool operator > (const room& r) const {
            return sz > r.sz;
        }
    };
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        priority_queue<room, vector<room>, greater<room>> pq;
        int n = rooms.size();
        vector<int> v;
        for (int q = 0; q < queries.size(); q++) {
            v.push_back(q);
        }
        sort(v.begin(), v.end(), [&](int a, int b) {
            return queries[a][1] < queries[b][1];
        });
        vector<int> res(queries.size());
        set<int> s;
        for (auto &v: rooms) {
            room tmp;
            tmp.id = v[0];
            tmp.sz = v[1];
            pq.push(tmp);
            s.insert(v[0]);
        }
        for (int q: v) {
            int minsz = queries[q][1], prefer = queries[q][0];
            while (!pq.empty() && pq.top().sz < minsz) {
                room tmp = pq.top();
                pq.pop();
                s.erase(tmp.id);
            }
            if (pq.empty()) {
                res[q] = -1;
                continue;
            }
            auto it = s.lower_bound(prefer);
            int val = *it;
            if (it != s.begin()) {
                it--;
                if (abs(prefer - *it) <= abs(prefer - val)) val = *it;
            }
            res[q] = val;
        }
        return res;
    }
};
