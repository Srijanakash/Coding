/*
 * Given a string S consisting of lowercase Latin Letters. Find the first non-repeating character in S.

Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
Example 2:

Input:
S = zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is
the character which is non-repeating.
 */



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
        unordered_map<char, int>umap;
        for(int i=0;i<S.size();i++)
            umap[S[i]]++;
        for(int i=0;i<S.size();i++)
            if(umap[S[i]]==1)
                return S[i];
        return '$';
    }

};

// { Driver Code Starts.

int main() {

	int T;
	cin >> T;

	while(T--)
	{

	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if(ans != '$')
	    cout << ans;
        else cout << "-1";

        cout << endl;

	}

	return 0;
}
  // } Driver Code Ends
