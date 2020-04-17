/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution 
{
public:
    int numTrees(int n) 
    {
        if(n<=1)
            return 1;
        //long long int T[n+1];
        vector<long long int>T;
        //T[0]=1;
        T.push_back(1);
        T.push_back(1);
        //T[1]=1;
        for(int i=2;i<=n;i++)
        {
            long long int ans=0;
            for(int j=0;j<i;j++)
                ans+=T[j]*T[i-j-1];
            //T[i]=ans;
            T.push_back(ans);
        }
        return T[n];
    }
};
