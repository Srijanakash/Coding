/*
 * A number is called good if it contains only 1's and 2's. Given an integer N, the task is to find Nth good number

Note: Some good numbers are 1, 2, 11, 12, 21, 22 ........

Input:
1. The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
2. The first line of each test case contains a single integer N.


Output: For each test case, print the Nth good number
Constraints:
1. 1 <= T <= 100
2. 1 <= N <= 104

Example:
Input:
2
5
10000

Output:
21
1122211121112
 */



#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define ll long long int
#define mp make_pair
#define vi vector<int>
using namespace std;
string nthGoodNumber(int n)
{
    queue<string>q;
    q.push("1");
    q.push("2");
    for(int i=1;i<n;i++)
    {
        string curr=q.front();
        q.pop();
        q.push(curr + "1");
        q.push(curr + "2");
    }
    return q.front();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin.ignore();
    for(;t>0;t--)
    {
        int n;
        cin>>n;
        cout<<nthGoodNumber(n)<<"\n";
    }
	return 0;
}
