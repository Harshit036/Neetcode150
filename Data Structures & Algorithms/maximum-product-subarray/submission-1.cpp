class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int ans = 0;
        int prefix = 1, suffix = 1;
        for(int i = 0; i < n; i++){
            prefix = prefix * nums[i];
            ans = max(ans, prefix);
            if(prefix == 0) prefix = 1;
        }
        for(int i = n-1; i >= 0; i--){
            suffix = suffix * nums[i];
            ans = max(ans, suffix);
            if(suffix == 0) suffix = 1;
        }
        return ans;
    }
};
