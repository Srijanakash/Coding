/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution 
{
    void BFSUtil(int i,int j,vector<vector<char>>&adj,int n,int m)
    {
        static int rowNum[]={-1,0,0,1};
        static int colNum[]={0,1,-1,0};
        queue<pair<int,int>>q;
        q.push(make_pair(i,j));
        adj[i][j]='2';
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int xx=x+rowNum[i],yy=y+colNum[i];
                if(xx>=0 && xx<n && yy>=0 
                    && yy<m && adj[xx][yy]=='1')
                {
                    q.push(make_pair(xx,yy));
                    adj[xx][yy]='2';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& A) 
    {
        int N=A.size();
        if(N==0)
            return 0;
        int M=A[0].size();
        int count=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(A[i][j]=='1')
                {
                    BFSUtil(i,j,A,N,M);
                    count++;
                }
            }
        }
        return count;
    }
};
