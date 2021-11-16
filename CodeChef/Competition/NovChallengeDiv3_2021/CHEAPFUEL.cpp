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
    int t, x, y, a, b, k;
    cin>>t;
    for(;t>0;t--)
    {
        cin>>x>>y>>a>>b>>k;
        if(x + a*k < y + b*k)
            cout<<"PETROL\n";
        else if(x + a*k > y + b*k)
            cout<<"DIESEL\n";
        else
            cout<<"SAME PRICE\n";
    }
    return 0;
}
