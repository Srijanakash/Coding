/*
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. 
If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
    
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
*/

class Solution 
{
    struct MyComp 
    {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) 
        {
            if(a.first != b.first)
                return a.first > b.first;
            else
                return a.second < b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int>umap;
        for(int i=0;i<words.size();i++)
            umap[words[i]]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, MyComp> pq;
        for(auto i=umap.begin();i!=umap.end();i++)
        {
            pq.push(make_pair(i->second, i->first));
            if(pq.size() > k) 
                pq.pop();
        }
        vector<string>res;
        while(!pq.empty()) 
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
