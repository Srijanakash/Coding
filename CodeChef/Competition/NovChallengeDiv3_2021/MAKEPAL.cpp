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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(;t>0;t--)
    {
        int minChanges = 0, n, x;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x % 2 == 1)
                minChanges++;
        }
        if(minChanges % 2 == 1)
            minChanges --;
        minChanges /= 2;
        cout<<minChanges<<"\n";
    }
    return 0;
}
