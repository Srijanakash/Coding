/*
 * Given a string S, the task is to find the bracket numbers.

Example 1:

Input:  S = "(aa(bdc))p(dee)​"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) has been
assigned the numbers as: 1 2 2 1 3 3.
Example 2:

Input:  S = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( has been assigned
the numbers as: 1 2 3 4 4 5
User Task:
Your task is to complete the function barcketNumbers()
which takes a single string as input and returns a list of numbers. You do not need to take any input or print anything.
 */



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution
{
public:

	vector<int> barcketNumbers(string s)
	{
	    // Your code goes here
	    int count = 1;
	    stack<int>st;
	    vector<int>res;
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i] == '(')
	        {
	            st.push(count);
	            res.push_back(count);
	            count++;
	        }
	        else if(s[i]==')')
	        {
	            res.push_back(st.top());
	            st.pop();
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.

int main()
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.barcketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends
