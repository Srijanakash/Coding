/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

class Solution 
{
    void findCombinations(vector<int>&candidates,vector<int>&elements,vector<vector<int>>&res,int target,int start)
    {
        if(!target)
        {
            res.push_back(elements);
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            if(candidates[i]>target)
                break;
            elements.push_back(candidates[i]);
            findCombinations(candidates,elements,res,target-candidates[i],i);
            elements.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>res;
        vector<int>elements;
        sort(candidates.begin(),candidates.end());
        findCombinations(candidates,elements,res,target,0);
        return res;
    }
};
