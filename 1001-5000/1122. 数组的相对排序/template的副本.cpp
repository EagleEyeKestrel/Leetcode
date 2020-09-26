//
//  main.cpp
//  简单题，但第一次知道c++11 lambda表达式里，[]里面可以capture局部变量
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int rank[1024];
        for(int i = 0; i <= 1000; i++) rank[i] = INT_MAX;
        for(int i = 0; i < arr2.size(); i++) {
            rank[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [rank](int a, int b) {
            if(rank[a] == rank[b]) return a < b;
            return rank[a] < rank[b];
        });
        return arr1;
    }
};
