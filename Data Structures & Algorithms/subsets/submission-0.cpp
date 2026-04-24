class Solution {
public:
    void func(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        func(index+1, nums, temp, ans);
        temp.pop_back();
        func(index+1, nums, temp, ans);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        func(0, nums, temp, ans);
        return ans;
    }
};
