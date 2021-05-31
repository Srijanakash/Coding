/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/

class Solution
{
public:
    string defangIPaddr(string address) 
    {
        string res,word="";
        int n=address.length();
        for(int i=0;i<n;i++)
        {
            if(isdigit(address[i]))
                word+=address[i];
            else
            {
                res+=word+'['+'\.'+']';
                word="";
            }
        }
        res+=word;
        return res;
    }
};
