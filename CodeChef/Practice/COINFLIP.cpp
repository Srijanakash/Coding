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
    int t, g, n, i, q;
    cin>>t;
    for(;t>0;t--)
    {
        cin>>g;
        for(;g>0;g--)
        {
            cin>>i>>n>>q;
            if(n%2 == 0 || i==q)
                cout<<n/2<<"\n";
            else
                cout<<n/2+1<<"\n";
        }
    }
}