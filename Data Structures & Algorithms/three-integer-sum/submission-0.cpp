class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        for(int i = 0; i < n; i++){
            int j = i+1;
            int k = n-1;
            int sum = 0 - nums[i];
            while(j < k){
                if(nums[j]+nums[k] == sum){
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                } else if(nums[j]+nums[k] < sum){
                    j++;
                } else {
                    k--;
                }
            }
        }
        vector<vector<int>> fans;
        for(auto it : ans) fans.push_back(it);
        return fans;
    }
};
