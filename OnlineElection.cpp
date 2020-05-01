/*
In an election, the i-th vote was cast for persons[i] at time times[i].
Now, we would like to implement the following query function: TopVotedCandidate.q(int t) 
will return the number of the person that was leading the election at time t.  
Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.

Example 1:

Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
*/

class TopVotedCandidate 
{
    vector<pair<int,int>>v;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) 
    {
        unordered_map<int,int>umap;
        int leader=-1,m=0;
        for(int i=0;i<persons.size();i++)
        {
            int p=persons[i],t=times[i];
            umap[p]++;
            if(umap[p]>=m)
            {
                if(leader!=p)
                {
                    leader=p;
                    v.push_back({leader,t});
                }
                if(umap[p]>m)
                    m=umap[p];
            }
        }
    }
    
    int q(int t) 
    {
        int lo = 1, hi = v.size();
        while (lo < hi) 
        {
            int mi = lo + (hi - lo) / 2;
            if (v[mi].second <= t)
                lo = mi + 1;
            else
                hi = mi;
        }

        return v[lo-1].first;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
