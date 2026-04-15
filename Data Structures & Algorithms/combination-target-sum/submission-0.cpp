class Solution {
public:
    void func(int index, vector<int> &nums, int target, vector<int> &temp, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(index == nums.size()) return;
        if(target - nums[index] >= 0){
            temp.push_back(nums[index]);
            func(index, nums, target - nums[index], temp, ans);
            temp.pop_back();
        }
        func(index+1, nums, target, temp, ans);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        func(0, nums, target, temp, ans);
        return ans;
    }
};
