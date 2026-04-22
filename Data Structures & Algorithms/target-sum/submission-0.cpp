class Solution {
public:
    int func(int index, int target, vector<int> &nums){
        if(index == nums.size()){
            return (target == 0);
        }        
        int left = func(index+1, target-nums[index], nums);
        int right = func(index+1, target+nums[index], nums);
        return left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int ans = func(0, target, nums);
        return ans;
    }
};
