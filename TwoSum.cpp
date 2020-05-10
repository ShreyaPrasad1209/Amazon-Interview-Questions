class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans; int j=1;
        if(!nums.size())
            ans.push_back(0);
       
        unordered_map<int,int>M;
        int x;
        for(int i =0; i<nums.size(); i++){
            x = target-nums[i];
            auto itr = M.find(x);         
            if(itr != M.end()){
                ans.push_back(i);
                ans.push_back(itr->second);
            }
            M[nums[i]] = i;
        }
        return ans;
    }
};

//Time Complexity: O(n)
//LeetCode Link: https://leetcode.com/problems/two-sum/
