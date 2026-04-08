class Solution {
public:
    bool isValid(int k, vector<int> &piles, int h){
        int count = 0;
        for(int i = 0; i < piles.size(); i++){
            count += (piles[i]+k-1)/k;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 1e9, ans;
        while(low <= high){
            int mid = high - (high - low) / 2;
            if(isValid(mid, piles, h)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        } 
        return ans;
    }
};
