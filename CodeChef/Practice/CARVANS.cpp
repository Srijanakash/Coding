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
        int n, maxSpeed;
        vector<int> speed(n);
        cin>>n;
        int carsWithMaxSpeed = 0;
        for(int i=0;i<n;i++)
            cin>>speed[i];
        maxSpeed=speed[0];
        for(int i=0;i<n;i++)
        {
            if(speed[i]<=maxSpeed)
            {
                carsWithMaxSpeed++;
                maxSpeed=speed[i];
            }
        }
        cout<<carsWithMaxSpeed<<"\n";
    }
}