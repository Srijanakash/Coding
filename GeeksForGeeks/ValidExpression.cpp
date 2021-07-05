/*
 * Given a string S, composed of different combinations of '(' , ')', '{', '}', '[', ']'.
 * The task is to verify the validity of the arrangement.
Note: Ignore the precedence of brackets.

Example 1:

Input:
S = ()[]{}
Output: 1
Explanation: The arrangement is valid.


Example 2:

Input:
S = ())({}
Output: 0
Explanation: Arrangement is not valid.


Your Task:
You dont need to read input or print anything. Complete the function valid() which takes S as input
and returns a boolean value denoting whether the arrangement is valid or not.
 */



// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
    // code here
    stack<char>st;
    st.push('#');
    string open = "({[", close = ")}]";
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == open[0] || s[i] == open[1] || s[i] == open[2])
            st.push(s[i]);
        else if((s[i] == close[0] && st.top() == open[0]) ||
                (s[i] == close[1] && st.top() == open[1]) ||
                (s[i] == close[2] && st.top() == open[2]))
                st.pop();
        else
            return false;
    }
    return st.size() == 1;
}
