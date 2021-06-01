//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
//Complete this function
long long minimumNumberOfCoins(int coins[],int m,int v)
{
    long long table[v+1];
    table[0]=0;
    for(int i=1;i<=v;i++)
    table[i]=INT_MAX;
    sort(coins,coins+m);
    for(int i=0;i<=v;i++)
    {
        for(int j=0;j<m;j++) 
        {
            if(coins[j]<=i)
            {
                table[i]=min(table[i],1+table[i-coins[j]]);
                
            }
            else
                break;
        }
    }
    return table[v]==INT_MAX?-1:table[v]; 
}
// { Driver Code Starts.
int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int value;
	    cin>>value;
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
