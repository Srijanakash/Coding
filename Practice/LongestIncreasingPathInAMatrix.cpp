/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution 
{
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}} ;
    int dfs(int i, int j, vector<vector<int>>& A, vector<vector<int>>& mem, int count)
    {
        if (mem[i][j] != -1)
            return mem[i][j]+count ;
        int res = 0 ;
        for (auto d : dir)
        {
            int nextx = i + d[0] ;
            int nexty = j + d[1] ;
            bool cond_exit = (nextx<0||nexty<0||nextx>=A.size()||nexty>=A[0].size()) ;
            if (!cond_exit)
            {
                if (A[i][j]<A[nextx][nexty]) 
                    res = max(res, dfs(nextx, nexty, A, mem, 1)) ;
            }
        }
        mem[i][j] = res ;
        return count+res ;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& A) 
    {
        if (A.empty()) 
            return 0 ;
        int m = A.size() ;
        int n = A[0].size() ;
        vector<vector<int>> mem(m, vector<int>(n, -1)) ;
        int res = 0 ;
        for(int i = 0 ; i < m ; i++)
            for (int j = 0 ; j < n ; j++)
                res = max(res, dfs(i, j, A, mem, 1)) ;
        return res ;
    }
};
