//Method 1: Using STL
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
            nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

//Method 2: Iteration

int removeElement(vector<int>& nums, int val) {
        for(auto it=nums.begin();it!=nums.end();it++){
            if(*it==val){
                nums.erase(it);
                --it;
            }
        }
        return nums.size();
    }
    
    
 //Runtime: 4ms
 //LeetCode: https://leetcode.com/problems/remove-element/

