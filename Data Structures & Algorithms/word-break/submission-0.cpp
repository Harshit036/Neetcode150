class Solution {
public:
    bool func(int index, string s, unordered_set<string> &st, vector<int> &dp){
        if(index == s.size()) return true;
        if(dp[index] != -1) return dp[index];
        for(int k = index; k < s.size(); k++){
            string subString = s.substr(index, k-index+1);
            if(st.find(subString) != st.end()){
                if(func(k+1, s, st, dp)) return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        int n = s.size();
        vector<int> dp(n+1, -1);
        for(auto it : wordDict) st.insert(it);
        bool ans = func(0, s, st, dp);
        return ans;
    }
};
