//
//  main.cpp
//  最后的结果肯定是从两头各取一段(也可能只从一头取k)
//  等价于从中间找一段，和最小
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = n - k, sum = 0, tmpSum = 0;
        for (int i = 0; i < n; i++) sum += cardPoints[i];
        int minSum = sum;
        for (int r = 0; r < n; r++) {
            tmpSum += cardPoints[r];
            if (r >= l) tmpSum -= cardPoints[r - l];
            if (r >= l - 1) minSum = min(minSum, tmpSum);
        }
        return sum - minSum;
    }
};
