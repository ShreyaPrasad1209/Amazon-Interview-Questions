vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; ++i){
            if(i == 0 || nums[i] != nums[i-1]){
                int j = i + 1, k = n-1;
                while(j < k){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0){
                        result.push_back({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j+1]) j++;
                        while(j < k && nums[k] == nums[k-1]) k--;
                        j++; k--;
                    }
                    else if (sum > 0) k--;
                    else j++;
                }
            }
        }
        return result;
    }
    
    //LeetCode Link: https://leetcode.com/problems/3sum/
    //Space Complexity: O(n)
    //Time: O(n^2)
    //Intuition: Fix ith element and apply two sum logic from i+1(j) to n-1(k) and when nums[i]+nums[j]+nums[k]==0, append it to the list. 
    //Make sure that if duplicate elements occur, skip them.
