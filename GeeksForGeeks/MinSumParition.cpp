using namespace std;
int findMin(vector<int>v,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=v[i];
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=sum;i++)
        dp[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(v[i-1]<=j)
                dp[i][j]|=dp[i-1][j-v[i-1]];
        }
    }
    int ans;
    for(int i=sum/2;i>=0;i--)
    {
        if(dp[n][i])
        {
            ans=sum-2*i;
            break;
        }
    }
    return ans;
}
int main()
{
    int t,n,x;
    cin>>t;
    for(;t>0;t--)
    {
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            v.pb(x);
        }
        cout<<findMin(v,n)<<endl;
    }
	return 0;
}
