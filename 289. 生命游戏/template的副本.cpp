//
//  main.cpp
//  小技巧，把livetodie的标记为2，dietolive标记为3
//  Copyright © 2020 ji luyang. All rights reserved.
//
 
class Solution {
public:
    int direx[8]={-1,-1,-1,0,0,1,1,1};
    int direy[8]={-1,0,1,-1,1,-1,0,1};
    bool inmap(int i,int j,int m,int n){
        return i>=0&&i<m&&j>=0&&j<n;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        //l-d:2 d-l:3
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt=0;
                for(int k=0;k<8;k++){
                    int xx=i+direx[k],yy=j+direy[k];
                    if(inmap(xx,yy,m,n)){
                        if(board[xx][yy]==2||board[xx][yy]==1) cnt++;
                    }
                }
                if(board[i][j]==1&&(cnt<2||cnt>3)) board[i][j]=2;
                if(board[i][j]==0&&cnt==3) board[i][j]=3;
            }
        }
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) board[i][j]%=2;
    }
};
