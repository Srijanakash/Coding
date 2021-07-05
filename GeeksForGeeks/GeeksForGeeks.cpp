/*
 * Geek prepared N questions for developers hiring challenge of the GeeksforGeeks,
 * but the hiring manager wants only one question in the contest and he asked geek
 * to give the best problem out of N problems. Geek thinks that all the questions are best
 * and he confused to choose a single problem. So, geek came with a game.
 * Geek placed all the problems side by side from 1 to N. He takes out the first problem
 * and inserts it at the end and removes the next first problem from the set. He repeats the
 * same process until a single problem remains. The task is to find a single last problem.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
2. The first line of each test case contains a single integer N.


Output: For each test case, print the last problem which remains

Constraints:
1. 1 <= T <= 100
2. 1 <= N <= 104

Example:
Input:
2
5
4

Output:
3
1

Explanation:
Test Case 1: {1, 2, 3, 4, 5} -> {3, 4, 5, 1} -> {5, 1, 3} -> {3, 5} -> {3}
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
int lastProblemNumber(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
        q.push(i);
    while(q.size()!=1)
    {
        q.push(q.front());
        q.pop();
        q.pop();
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
        cout<<lastProblemNumber(n)<<"\n";
    }
	return 0;
}
