//
//  main.cpp
//  我的解法：座位只有三种坐法，2345，4567，6789
//  每一行最多坐两个。对于有人预定的排，单独计算一下这一排能坐多少
//  座位排序之后，tmp记录第i个座位是否有人
//  写的不优雅。看到评论区，用位运算实现，可以非常优雅
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        sort(seats.begin(), seats.end(), [](auto &a, auto&b) {
            return a[0] < b[0];
        });
        int res = n << 1, i = 0;
        while (i < seats.size()) {
            int tmp[11];
            memset(tmp, 0, sizeof(tmp));
            int j = i;
            while (j < seats.size()) {
                tmp[seats[j][1]]++;
                if (j + 1 == seats.size()) break;
                if (seats[j + 1][0] == seats[j][0]) j++;
                else break;
            }
            i = j + 1;
            int cnt = 0;
            if (!tmp[2] && !tmp[3] && !tmp[4] && !tmp[5]) {
                for (int k = 2; k <= 5; k++) tmp[k] = 1;
                cnt++;
            }
            if (!tmp[4] && !tmp[5] && !tmp[6] && !tmp[7]) {
                for (int k = 4; k <= 7; k++) tmp[k] = 1;
                cnt++;
            }
            if (!tmp[6] && !tmp[7] && !tmp[8] && !tmp[9]) {
                for (int k = 6; k <= 9; k++) tmp[k] = 1;
                cnt++;
            }
            res -= (2 - cnt);
        }
        return res;
    }
};

/*
 int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
     unordered_map<int, int> record;  // 右侧的int当为位图来用
     for(auto &vec : reservedSeats) {
         record[vec[0]] |= (1 << (vec[1]-1));
     }
     int total = (n - record.size()) * 2;
     int a = 0b0111111110;
     int b = 0b0000011110;
     int c = 0b0111100000;
     int d = 0b0001111000;
     for (const auto &p : record) {
         if ((p.second & a) == 0) { total += 2; continue; }
         if ((p.second & b) == 0) { total += 1; continue; }
         if ((p.second & c) == 0) { total += 1; continue; }
         if ((p.second & d) == 0) { total += 1; continue; }
     }
     return total;
 }
 */
