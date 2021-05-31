/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.
 
Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

class Solution 
{
public:
	vector<vector<char>> b;
	vector<string> ans;
	string s;
	int m;
	int n;
	void helper(string ss)
    {
		s=ss;
		for(int i=0;i<m;i++)
        {
			for(int j=0;j<n;j++)
            {
				if(b[i][j]!=s[0]) 
                    continue;
				if(dfs(i,j,0))
                {
					ans.push_back(s);
					return;
				}
			}
		}
	}
	bool dfs(int x, int y,int d)
    {    
		if(x<0 || x>=m ||y<0 || y>=n || s[d]!=b[x][y]) 
            return false;
		if(d==s.size()-1) 
            return true;
		char cur=b[x][y];
		b[x][y]='#';
		bool found=dfs(x+1,y,d+1) || dfs(x-1,y,d+1) ||
				   dfs(x,y+1,d+1) || dfs(x,y-1,d+1);
		b[x][y]=cur;
		return found;  
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
		b=board;
		m=board.size();
		n=board[0].size();
		for(int i=0;i<words.size();i++)
			helper(words[i]);
		return ans;  
	}
};
