/*
 * Given an array A[] of integers, sort the array according to frequency of elements.
 * That is elements that have higher frequency come first. If frequencies of two elements are same,
 * then smaller number comes first.

Input:
The first line of input contains an integer T denoting the number of test cases.
The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each testcase, in a new line, print each sorted array in a seperate line.
For each array its numbers should be seperated by space.


Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5
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
bool comp(const pair<int, int>a, const pair<int, int>b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
void sortedElements(vector<int> &v)
{
    unordered_map<int, int>umap;
    for(int i=0;i<v.size();i++)
        umap[v[i]]++;
    vector<pair<int, int>>sortedV;
    copy(umap.begin(), umap.end(), back_inserter(sortedV));
    sort(sortedV.begin(), sortedV.end(), comp);
    for(int i = 0 ; i < sortedV.size() ; i++)
        for(int j = 0 ; j < sortedV[i].second ; j++)
            cout<<sortedV[i].first<<" ";
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
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sortedElements(v);
        cout<<"\n";
    }
	return 0;
}
