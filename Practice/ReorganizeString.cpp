/*
Given a string S, check if the letters can be rearranged 
so that two characters that are adjacent to each other are not the same.
If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
*/

const int MAX_CHAR = 26; 
struct Key 
{ 
    int freq;
    char ch; 
    bool operator<(const Key &k) const
    { 
        return freq < k.freq; 
    } 
}; 
class Solution 
{
public:
    string reorganizeString(string S) 
    {
        int n = S.length(); 
        int count[MAX_CHAR] = {0}; 
        for (int i = 0 ; i < n ; i++) 
            count[S[i]-'a']++; 
        priority_queue< Key > pq; 
        for (char c = 'a' ; c <= 'z' ; c++) 
            if (count[c-'a']) 
                pq.push(Key{count[c-'a'],c}); 
        string str = ""; 
        Key prev {-1,'#'}; 
        while (!pq.empty()) 
        { 
            Key k = pq.top(); 
            pq.pop(); 
            str = str + k.ch; 
            if (prev.freq > 0) 
                pq.push(prev); 
            (k.freq)--; 
            prev = k; 
        } 
        return n==str.length()?str:"";
    }
};
