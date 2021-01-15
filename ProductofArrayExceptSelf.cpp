class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>right(n), left(n);
        right[0]=1;
        left[n-1]=1;
        
        for(int i=1;i<n;i++)
        {
            right[i]=nums[i-1]*right[i-1];
        }
        
           for(int i=n-2;i>=0;i--)
        {
            left[i]=nums[i+1]*left[i+1];
        }
        
        vector<int>ans(n);
        
        for(int i=0;i<n;i++)
        {
            ans[i]=right[i]*left[i];
        }
        
        return ans;
    }
};

//Logic: Take two vectors right and left to store the product of all the array elements from start, up to that index and another array to store the product of all the array elements from the end of the array to that index.
To get the product excluding that index, multiply the prefix product up to index i-1 with the suffix product up to index i+1.

//Time Complexity: O(n)
