//
//  main.cpp
//  太蠢了，开始没看到每个学生位置要不同。从大到小依次坐
//  Copyright © 2021 ji luyang. All rights reserved.
//

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int res = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        for (int i = 0; i < seats.size(); i++) res += abs(seats[i] - students[i]);
        return res;
    }
};
