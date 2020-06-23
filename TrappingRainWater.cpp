Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. 

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int result=0;
        /*
        stack<int>s;
        for(int i=0;i<height.size();i++)
        {
            while(!s.empty() && height[i]>height[s.top()])
            {
                int top=s.top();
                s.pop();
                if(s.empty())
                    break;
                int dist=i-s.top()-1;
                int boundedHeight=min(height[i],height[s.top()])-height[top];
                result+=dist*boundedHeight;
            }
            s.push(i);
        }
        */
        int left=0,right=height.size()-1;
        int leftMax=0,rightMax=0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(height[left]>=leftMax)
                    leftMax=height[left];
                else
                    result+=leftMax-height[left];
                left++;
            }
            else
            {
                if(height[right]>=rightMax)
                    rightMax=height[right];
                else
                    result+=rightMax-height[right];
                right--;
            }
        }
        return result;
    }
};
