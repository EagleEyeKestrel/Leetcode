//
//  main.cpp
//  这个单调栈比我想的更好，因为一个块只需要记录最大值其实就够了
//  num大于等于栈顶，直接放
//  如果小于栈顶，那么num和栈顶将会组成一个新块。
//  组成新块的同时，要把栈顶下面所有最大值大于num的块扔了，直到剩下的栈顶元素小于等于num
//  说明剩下的元素都小于等于num了，此时放入head，这个head就是和num合并的新块
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
        for(int num: arr) {
            if(!s.empty() && s.top() > num) {
                int head = s.top();
                s.pop();
                while(!s.empty() && s.top() > num) s.pop();
                s.push(head);
            } else {
                s.push(num);
            }
        }
        return s.size();
    }
};
