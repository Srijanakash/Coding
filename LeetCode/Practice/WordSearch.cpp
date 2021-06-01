/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

class Solution 
{
    bool dfs(vector<vector<char>>& board, int i, int j, string& word) 
    {
        if (!word.size())
            return true;
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) 
                    || dfs(board, i, j-1, s) || dfs(board, i, j+1, s);
        board[i][j] = c;
        return ret;
    }
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        for (int i = 0; i < board.size(); i++) 
            for (int j = 0; j < board[0].size(); j++) 
                if (dfs(board, i, j, word))
                    return true;
        return false;
    }
};
