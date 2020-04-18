/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution 
{
    struct MyComp 
    {
        bool operator() (const pair<int, char>& a, const pair<int, char>& b) 
        {
            if(a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int>umap;
        for(int i=0;i<s.length();i++)
            umap[s[i]]++;
        priority_queue<pair<int, char>, vector<pair<int, char>>, MyComp> pq;
        for(auto i=umap.begin();i!=umap.end();i++)
            pq.push(make_pair(i->second, i->first));
        string res;
        while(!pq.empty()) 
        {
            for(int i=0;i<pq.top().first;i++)
                res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
