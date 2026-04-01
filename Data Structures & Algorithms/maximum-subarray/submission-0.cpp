class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int val = 0;
        int maxi = -1e9;
        for(int i = 0; i < nums.size(); i++){
            val += nums[i];
            maxi = max(maxi, val);
            if(val < 0) val = 0;
        }
        return maxi;
    }
};
