//
//  main.cpp
//  算出六个距离，判断是不是四个相等，另两个相等，并且是不是另四个的根号2倍，并且非0
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    long dist(vector<int> &v1, vector<int> &v2) {
        return (long)(v1[0] - v2[0]) * (v1[0] - v2[0]) + (long)(v1[1] - v2[1]) * (v1[1] - v2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        long s1 = dist(p1, p2), s2 = dist(p1, p3), s3 = dist(p1, p4);
        long s4 = dist(p2, p3), s5 = dist(p2, p4), s6 = dist(p3, p4);
        vector<long> dists = {s1, s2, s3, s4, s5, s6};
        sort(dists.begin(), dists.end());
        return dists[0] == dists[1] && dists[0] == dists[2] && dists[0] == dists[3] && dists[4] == dists[5] && dists[4] == 2 * dists[0] && dists[0];
    }
};
