/*
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
 *
 * An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:
 *
 *
 * s = s1 + s2 + ... + sn
 * t = t1 + t2 + ... + tm
 * |n - m| <= 1
 * The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
 *
 * Note: a + b is the concatenation of strings a and b.
 *
 *
 * Example 1:
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 *
 * Example 2:
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 *
 * Example 3:
 *
 * Input: s1 = "", s2 = "", s3 = ""
 * Output: true
 */


class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.length() + s2.length() != s3.length())
            return false;
        vector<bool>dp(s2.length() + 1);
        for(int i = 0; i <= s1.length(); i++)
        {
            for(int j = 0; j <= s2.length(); j++)
            {
                if(i == 0 && j == 0)
                    dp[j] = true;
                else if (i == 0)
                    dp[j] = dp[j-1] && s2[j - 1] == s3[i + j - 1];
                else if (j == 0)
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                else
                    dp[j] = (dp[j-1] && s2[j - 1] == s3[i + j - 1]) || (dp[j] && s1[i - 1] == s3[i + j - 1]);
            }
        }
        return dp[s2.length()];
    }
};