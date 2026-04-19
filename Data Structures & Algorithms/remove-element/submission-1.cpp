class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = n-1, k = 0;
        for(int i = 0; i < n && i <= j; i++){
            while(nums[i] == val && i <= j){
                nums[i] = nums[j];
                j--;
            } 
        }
        cout << j << "\n";
        return j+1;
    }
};