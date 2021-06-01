// Initial Template for C++
/* script for test case http://code.geeksforgeeks.org/PetjYq */
#include <bits/stdc++.h>

using namespace std;

string printOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = printOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
// User function Template for C++
/*The function should return a string denoting the
order of the words in the Alien Dictionary */
typedef vector<char> vc;
void dfs(char s,unordered_map<char,vc> &mp,unordered_map<char,bool> &vis,stack<char> &st)
{
    vis[s]=true;
    for(auto it=mp[s].begin();it!=mp[s].end();it++)
    {
        if(!vis[*it])
        dfs(*it,mp,vis,st);
    }
    st.push(s);
}

string printOrder(string dict[], int n, int k)
{
    unordered_map<char,vc> mp;
    unordered_map <char,bool> vis;
    for(int i=0;i<n-1;i++)
    {
        int l1=dict[i].length();
        int l2=dict[i+1].length();
        int j=0;
        while(j<l1&&j<l2)
        {
            if(dict[i][j]!=dict[i+1][j])
            {
                char c1=dict[i][j];
                char c2=dict[i+1][j];
                mp[c1].push_back(c2);
                vis[c1]=vis[c2]=false;
                break;
            } j++;
        }
    }
       
        stack<char> st;
        
        for(auto it=vis.begin();it!=vis.end();it++)
        {   char c=it->first;
            if(!vis[c])
            dfs(c,mp,vis,st);}
        
        string res;
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        //cout<<res<<endl;
        return res;
}
