//
//  main.cpp
//  第一种比较简单的思路，heights[i]表示当前第i列的高度。
//  遍历到每一行的时候，转化成柱状图中最大的矩形问题！
//  Copyright © 2020 ji luyang. All rights reserved.
//

class Solution {
public:
    int heights[256];
    int f(int n){
        stack<int> s;
        int res = 0;
        s.push(-1);
        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && heights[i] <= heights[s.top()]) {
                int tmp = heights[s.top()];
                s.pop();
                res = max(res, tmp * (i - s.top() - 1));
            }
            s.push(i);
        }
        while (s.top() != -1) {
            int v = s.top();
            s.pop();
            res = max(res, heights[v] * (n - 1 - s.top()));
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        memset(heights, 0, sizeof(heights));
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            res = max(res, f(n));
        }
        return res;
    }
};

//  另一种思路，heights[i]的意义不变。增加两个滚动数组，l[i]和r[i]表示i往左/右能延伸到的最远的1/最近的0
//  但这是多行累计的结果，h[j]*(r[j]-l[j])就可以直接表示以h[j]为限制的矩形的最大面积
/*class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size();
        int left[n],right[n],height[n];
        for(int i=0;i<n;i++) right[i]=n;
        for(int i=0;i<n;i++) left[i]=0;
        for(int i=0;i<n;i++) height[i]=0;
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') height[j]=height[j]+1;
                else height[j]=0;
            }
            int curleft=0,curight=n;
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    curleft=j+1;
                    left[j]=0;
                }
                else left[j]=max(curleft,left[j]);
            }
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='0'){
                    right[j]=n;
                    curight=j;
                }
                else right[j]=min(right[j],curight);
            }
            for(int j=0;j<n;j++){
                res=max(res,height[j]*(right[j]-left[j]));
            }
        }
        return res;
    }
};
*/
