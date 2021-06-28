/*
 * You are given the string S . Compress the string when lower and upper cases are the same.
 * In compressed string characters should be in lowercase.

Example 1:

Input: S = "aaABBb"
Output: "3a3b"
Explanation: As 'a' appears 3 times
consecutively and 'b' also 3 times,
and 'b' and 'B' considered as same.
​Example 2:

Input: S = "aaacca"
Output: "3a2c1a"
Explanation: As 'a' appears 3 times
consecutively and 'c' also 2 times,
and then 'a' 1 time.
Your Task:
You don't need to read input or print anything. Your task is to complete the function transform()
which takes the string S as inputs and returns the compressed string.
 */




// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}

// } Driver Code Ends


string transform(string S)
{
    //complete the function here
    string  res="";
    int count=0;
    char c;
    for(int i=0;i<S.length();i++)
    {
        char ch = (char)tolower(S[i]);
        if(i==0)
        {
            c=ch;
            count++;
        }
        else if(ch == c)
            count++;
        else
        {
            res+=to_string(count)+c;
            c=ch;
            count = 1;
        }
    }
    res+=to_string(count)+c;
    return res;
}

