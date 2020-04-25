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
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> dict;
        for (auto str : strs) 
        {
            string key = str;
            sort(begin(key), end(key));
            dict[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for (const auto& [key, value] : dict) 
            res.emplace_back(value);
        return res;
    }
};
