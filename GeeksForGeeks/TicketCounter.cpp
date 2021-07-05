/*
 * N people standing in the queue of a movie ticket counter.
 * It is a weird counter, distributes tickets to first K people and
 * then last K people and again first K people and so on. The task is to find the last person to get the ticket.

Example: Let N = 9, K = 3, starting queue will like {1, 2, 3, 4, 5, 6, 7, 8, 9}.
After the first distribution queue will look like {4, 5, 6, 7, 8, 9}.
And after the second distribution queue will look like {4, 5, 6}. The last person to get the ticket will be 6.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
2. The first line of each test case contains two space-separated integers N and K.


Output: For each test case, print the last problem which remains

Constraints:
1. 1 <= T <= 10
2. 1 <= K<= N <= 105

Example:

Input:
2
9 3
25 7

Output:
6
15
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
int lastPersonToGetTicket(int N, int K)
{
    deque<int> dq;
    for(int i = 1; i <= N; i++)
        dq.push_back(i);
    int res;
    bool first = true;
    while(!dq.empty())
    {
        int k = K;
        if(first)
        {
            while(!dq.empty() and k--)
            {
                res = dq.front();
                dq.pop_front();
            }
            first = false;
        }
        else
        {
            while(!dq.empty() and k--)
            {
                res = dq.back();
                dq.pop_back();
            }
            first = true;
        }
    }
    return res;
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
        int n,k;
        cin>>n>>k;
        cout<<lastPersonToGetTicket(n, k)<<"\n";
    }
	return 0;
}
