class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
        {
            return 0;
        }
        
        int count=0;
        int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        
        
        left[0]=height[0];
        right[n-1]=height[n-1];
        
        //max in right subarray
        for(int i=1;i<height.size();i++)
        {
            left[i]=max(height[i], left[i-1]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1], height[i]);
        }
        
        for(int i=0;i<n-1;i++)
        {
            count+=(min(right[i], left[i]) - height[i]);
        }
         return count;
    }
    
};

//Logic: Find minimum of maximum height on either side of every index. 
//LeetCode Link: https://leetcode.com/problems/trapping-rain-water/
//Runtime: O(n)
