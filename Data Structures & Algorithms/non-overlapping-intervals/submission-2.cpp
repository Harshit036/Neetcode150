class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        vector<int> prev;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(prev.empty() || prev[1] <= intervals[i][0]){
                prev = intervals[i];
            } else {
                ans++;
            }
        }
        return ans;
    }
};

// [[1,10],[2,3],[3,4]]
