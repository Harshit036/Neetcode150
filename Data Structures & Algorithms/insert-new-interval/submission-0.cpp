class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& nIt) {
        int n = it.size();
        it.push_back(nIt);
        sort(it.begin(), it.end());
        vector<vector<int>> ans;
        for(int i = 0; i <= n; i++){
            if(ans.empty() || ans.back()[1] < it[i][0]){
                ans.push_back(it[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], it[i][1]);
            }
        }
        return ans;
    }
};
