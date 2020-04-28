/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().
*/

class Solution 
{
    bool checkStr(string haystack,string needle,int i)
    {
        int j,index;
        for(j=i,index=0;index<needle.length();j++,index++)
            if(haystack[j]!=needle[index])
                return false;
        return true;
            
    }
public:
    int strStr(string haystack, string needle) 
    {
        int n=haystack.length(),m=needle.length();
        if(m==0)
            return 0;
        for(int i=0;i<=n-m;i++)
        {
            if(haystack[i]==needle[0])
            {
                if(checkStr(haystack,needle,i))
                    return i;
            }
        }
        return -1;
    }
};
