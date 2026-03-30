class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 1;
        for(auto it : nums) val = val ^ it;
        return val ^ 1;
    }
};
