/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution 
{
    string findFrequency(string s)
    {
        int freq[26];
        memset(freq,  0,  sizeof(freq));
        for(int i=0;i<s.size();i++)
            freq[s[i]-'a']++;
        string res="";
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                for(int j=0;j<freq[i];j++)
                    res += (i+'a');
            }
            else
                res += '#';
        }
        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;
        for(int i=0;i<strs.size();i++)
        {
            string freqString = findFrequency(strs[i]);
            cout<<strs[i]<<" "<<freqString<<", ";
            umap[freqString].push_back(strs[i]);
        }
        for(auto it = umap.begin(); it!=umap.end();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
