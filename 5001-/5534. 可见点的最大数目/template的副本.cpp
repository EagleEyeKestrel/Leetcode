//
//  main.cpp
//  这里直接上的周赛ac的代码
//  大概就是对每个点，求出对于location的角度，然后滑动窗口来看最多有几个点
//  几个细节问题，用acos -1 求出派，然后atan返回的肯定是弧度制，这里统一成角度
//  然后把角度都统一在了0到360范围内
//  特判一下x相同的情况，判断一下是270度还是90度，还是和location重合（存在haso里，它一定在视野范围内
//  最后所有degrees排序。但要注意，第四象限和第一象限仍然可以互通，所以这里把degrees加上360又复制了一遍。也是当时WA了的原因
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    double pi = acos(-1);
    double f(double hudu) {
        return hudu / pi * 180;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> degrees;
        int haso = 0;
        for(auto &point: points) {
            int px = point[0], py = point[1];
            if(px == location[0]) {
                if(py > location[1]) {
                    degrees.push_back(90);
                } else if(py < location[1]) {
                    degrees.push_back(270);
                } else {
                    haso++;
                }
            } else {
                double k = (double)(location[1] - point[1]) / (location[0] - point[0]);
                if(k >= 0) {
                    if(location[0] < px) {
                        degrees.push_back(f(atan(k)));
                    } else {
                        degrees.push_back(f(atan(k)) + 180);
                    }
                } else {
                    if(location[0] < px) {
                        degrees.push_back(f(atan(k)) + 360);
                    } else {
                        degrees.push_back(f(atan(k)) + 180);
                    }
                }
            }
        }
        int l = 0, res = 0;
        sort(degrees.begin(), degrees.end());
        int n = degrees.size();
        for(int r = 0; r < n; r++) {
            degrees.push_back(degrees[r] + 360);
        }
        for(int r = 0; r < degrees.size(); r++) {
            while(l < r && degrees[r] - degrees[l] > angle) {
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res + haso;
    }
};
