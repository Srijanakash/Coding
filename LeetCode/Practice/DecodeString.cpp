/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], 
where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, 
square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits 
are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
*/




class Solution 
{
public:
    string decodeString(string s) 
    {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString;
        int k = 0;
        for (auto ch : s) 
        {
            if (isdigit(ch))
                k = k * 10 + ch - '0';
            else if (ch == '[') 
            {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            }
            else if (ch == ']') 
            {
                string decodedString = stringStack.top();
                stringStack.pop();
                for (int currentK = countStack.top(); currentK > 0; currentK--) 
                    decodedString = decodedString + currentString;
                countStack.pop();
                currentString = decodedString;
            } 
            else
                currentString = currentString + ch;
        }
        return currentString;
    }
};
