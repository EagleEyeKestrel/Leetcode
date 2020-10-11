//
//  main.cpp
//  比较有区分度的一道题，下面是我比赛时候的解法
//
//  不妨先考虑a的prefix和b的subfix，对于每个分割点，等价于检查a[0] a[1] ... a[i] b[i+1] b[i+2]...是不是回文
//  考虑相邻两次的变化，是由a[i] b[i+1] b[i+2]变成a[i] a[i+1] b[i+2]，对于回文串的影响只变动了一对字符
//  即a[i+1] 和它对称的位置。
//  所以一开始数b的b.size()/2对 对称位置，有多少对对称的，然后每次放上去一个a[i]，看这个a[i]是会增加一对对称还是减少一对
//  然后对于b的prefix+a的subfix直接类似处理就行，但实际上直接调用f(b,a)就可以了
//
//  一个要注意的地方是，now增减的时候，要判断i != n-1-i，这个地方差点让我WA一次
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int f(string a, string b) {
        int n = b.size();
        int l = 0, r = n - 1;
        int now = 0;
        while(l < r) {
            if(b[l] == b[r]) now++;
            l++;r--;
        }
        if(now == n / 2) return true;
        for(int i = 0; i < n; i++) {
            if(b[i] == b[n - 1 - i] && i != n - 1 - i) now--;
            if(a[i] == b[n - 1 - i] && i != n - 1 - i) now++;
            b[i] = a[i];
            if(now == n / 2) return true;
        }
        return false;
    }
    bool checkPalindromeFormation(string a, string b) {
        return f(a, b) || f(b, a);
    }
};
