class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int val = 1;
        for(int i = 0; i < n; i++){
            val--;
            val = max(val, nums[i]);
            if(val <= 0 && i != n-1) return false;
        }
        return true;
    }
};
