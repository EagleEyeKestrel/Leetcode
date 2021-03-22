//
//  main.cpp
//  暴力就行了。。或者用set优化一下查找？
//  要注意v erase的时候i要--
//  Copyright © 2021 ji luyang. All rights reserved.
//

class AuthenticationManager {
public:
    vector<pair<string, int>> v;
    int t;
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        v.push_back({ tokenId, currentTime });
    }
    
    void renew(string tokenId, int currentTime) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].first == tokenId && v[i].second + t > currentTime) {
                v[i].second = currentTime;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].second + t <= currentTime) {
                v.erase(v.begin() + i);
                i--;
            }
        }
        return v.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
