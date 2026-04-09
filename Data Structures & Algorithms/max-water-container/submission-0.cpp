class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int low = 0, high = heights.size()-1;
        while(low < high){
            ans = max(ans, min(heights[low], heights[high])*(high-low));
            if(heights[low] <= heights[high]) low++;
            else high--;
        }
        return ans;
    }
};
