/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

class Trie 
{
public:
    Trie* children[26];
    bool isLeaf=false;
    /** Initialize your data structure here. */
    Trie() 
    {
        memset(children, 0, sizeof children);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        Trie* t=this;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'a';
            if(t->children[index]==0) 
                t->children[index]=new Trie();
            t=t->children[index];
        }
        t->isLeaf=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie* t=this;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'a';
            if(t->children[index]==0) 
                return false;
            t=t->children[index];
        }
        return t->isLeaf;        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie* t=this;
        for(int i=0;i<prefix.length();i++)
        {
            int index=prefix[i]-'a';
            if(t->children[index]==0) 
                return false;
            t=t->children[index];
        }
        return true;        
    }
};
