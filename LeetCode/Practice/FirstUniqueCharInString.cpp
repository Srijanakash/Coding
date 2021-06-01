/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char,pair<int,int>>umap;
        for(int i=0;i<s.length();i++)
        {
            if(umap.find(s[i])==umap.end())
                umap[s[i]]={i,1};
            else
                umap[s[i]]={i,2};
        }
        int index=INT_MAX;
        for(auto i=umap.begin();i!=umap.end();i++)
            if(i->second.second==1)
                index=min(index,i->second.first);
        return index==INT_MAX?-1:index;
    }
};
