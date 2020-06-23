/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution 
{
    vector<string>result;
    void backtrack(string curr,int open,int close,int n)
    {
        if(curr.length()==2*n)
        {
            result.push_back(curr);
            return;
        }
        if(open<n)
            backtrack(curr+"(",open+1,close,n);
        if(close<open)
            backtrack(curr+")",open,close+1,n);
    }
public:
    vector<string> generateParenthesis(int n) 
    {
        backtrack("",0,0,n);
        return result;
    }
};
