class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            prefix[i] = maxi;
            maxi = max(maxi, height[i]);  
        } 
        maxi = 0;
        for(int i = n-1; i >= 0; i--){
            suffix[i] = maxi;
            maxi = max(maxi, height[i]);  
        } 
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(0, min(prefix[i], suffix[i]) - height[i]);
        }
        return ans;
    }
};
