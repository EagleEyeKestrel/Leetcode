//
//  main.cpp
//  一个很朴素的想法，把长方体的六种可能排列都放到一个序列里，变成LIS问题
//  加入了id属性，保证一个长方体不会和自己自增
//  比赛的时候一直WA不知道为什么
//  后来发现排序的时候一定要对xyz每一项都要递增，不能只是xy
//  如果不对z排序，可能是(1 2 4) (1 2 3)，后面的那个本可以和前面的叠加，但不排序，就算不到它了
//  很可惜啊，这次完全可以冲击奖品
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    struct point {
        int x, y, z, id;
    }points[610];
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        int len = 0;
        for(int i = 0; i < n; i++) {
            points[len].x = cuboids[i][0];
            points[len].y = cuboids[i][1];
            points[len].z = cuboids[i][2];
            points[len].id = i;
            len++;
            points[len].x = cuboids[i][0];
            points[len].z = cuboids[i][1];
            points[len].y = cuboids[i][2];
            points[len].id = i;
            len++;
            points[len].y = cuboids[i][0];
            points[len].x = cuboids[i][1];
            points[len].z = cuboids[i][2];
            points[len].id = i;
            len++;
            points[len].y = cuboids[i][0];
            points[len].z = cuboids[i][1];
            points[len].x = cuboids[i][2];
            points[len].id = i;
            len++;
            points[len].z = cuboids[i][0];
            points[len].x = cuboids[i][1];
            points[len].y = cuboids[i][2];
            points[len].id = i;
            len++;
            points[len].z = cuboids[i][0];
            points[len].y = cuboids[i][1];
            points[len].x = cuboids[i][2];
            points[len].id = i;
            len++;
        }
        sort(points, points + len, [](point& a, point& b) {
            if (a.x == b.x && a.y == b.y && a.z == b.z) return a.id < b.id;
            if (a.x == b.x && a.y == b.y) return a.z < b.z;
            if (a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        });
        int dp[len + 10];
        dp[0] = points[0].z;
        for(int i = 1; i < len; i++) {
            int tmp = 0;
            for(int j = 0; j < i; j++) {
                if ((points[j].x <= points[i].x && points[j].y <= points[i].y && points[j].z <= points[i].z && points[j].id != points[i].id)) {
                    tmp = max(tmp, dp[j]);
                }
            }
            dp[i] = tmp + points[i].z;
        }
        int res = 0;
        for(int i = 0; i < len; i++) res = max(res, dp[i]);
        return res;
    }
};
