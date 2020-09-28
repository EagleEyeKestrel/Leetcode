//
//  main.cpp
//  自己写的一种和直觉相近的做法。
//  单调栈，用一个node表示一个块，记录node里的最大值和最小值
//  每次遇到arr[i]，先把所有small比arr[i]大的弹出去
//  然后根据s是否为空，要么放入新块，要么并在弹完之后栈顶的块。
//  WA了一次，并块的时候，要注意s.top.big是等于两者的max，而非直接nowmax
//  因为有可能一个都没有弹，nowmax有可能小于栈顶的big
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    struct node{
        int small, big;
        node(int s, int b): small(s), big(b){}
    };
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<node> s;
        for(int i = 0; i < n; i++) {
            int nowmax = arr[i];
            while(!s.empty() && arr[i] < s.top().small) {
                nowmax = max(nowmax, s.top().big);
                s.pop();
            }
            if(s.empty()) {
                s.push(node(arr[i], nowmax));
            } else {
                if(arr[i] < s.top().big) {
                    s.top().big = max(s.top().big, nowmax);
                } else {
                    s.push(node(arr[i], nowmax));
                }
            }
        }
        return s.size();
    }
};
