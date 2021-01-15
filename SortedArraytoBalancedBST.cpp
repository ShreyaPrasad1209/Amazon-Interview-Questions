class Solution {
public:
    
    TreeNode* arrToBST(vector<int>&nums, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        
        int mid= (start+end)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
         root->left = arrToBST(nums, start, mid-1);
        root->right = arrToBST(nums,mid+1,end);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n=nums.size()-1;
        TreeNode* ans = arrToBST(nums, 0, n);
        return ans;    
    }
};
