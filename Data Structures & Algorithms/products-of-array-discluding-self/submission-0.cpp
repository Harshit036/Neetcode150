class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        int ans = 1;
        for(int i = 0; i < n; i++){
            prefix[i] = ans;
            ans *= nums[i];
        }
        ans = 1;
        for(int i = n-1; i >= 0; i--){
            suffix[i] = ans;
            ans *= nums[i];
        }

        vector<int> temp(n);
        for(int i = 0; i < n; i++) temp[i] = prefix[i] * suffix[i];
        return temp;
    }
};
