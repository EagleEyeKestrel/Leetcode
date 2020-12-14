//
//  main.cpp
//
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size(), maxl = releaseTimes[0];
        char res = keysPressed[0];
        for(int i = 1; i < n; i++) {
            if(releaseTimes[i] - releaseTimes[i - 1] > maxl) {
                maxl = releaseTimes[i] - releaseTimes[i - 1];
                res = keysPressed[i];
            } else if(releaseTimes[i] - releaseTimes[i - 1] == maxl) {
                res = max(res, keysPressed[i]);
            }
        }
        return res;
    }
};
