/*
Implement FreqStack, a class which simulates the operation of a stack-like data structure.
FreqStack has two functions:
push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.

Example 1:

Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
*/

class FreqStack 
{
    priority_queue<pair<int, pair<int, int>>> q;
    unordered_map<int, int> freq;
    int pos;
public:
    FreqStack() 
    {
        pos=0;
    }
    void push(int x) 
    {
        freq[x]++;
        q.push(make_pair(freq[x],make_pair(++pos, x)));
    }
    int pop() 
    {
        auto val = q.top();
        q.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
