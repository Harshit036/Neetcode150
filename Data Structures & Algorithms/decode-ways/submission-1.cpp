class Solution {
public:
    bool isValid(int i, int j, string s){
        if(s[i] == '0') return false;
        if(j-i+1 > 2) return false;
        int num = stoi(s.substr(i, j-i+1));
        if(num >= 1 && num <= 26) return true;
        return false;
    }
    int func(int index, string s, vector<int> &dp){
        if(index == s.size()) return 1;
        if(dp[index] != -1) return dp[index];
        int ans = 0;
        for(int k = index; k < s.size(); k++){
            if(isValid(index, k, s)){
                ans += func(k+1, s, dp);
            } else 
                break;
        }
        return dp[index] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return func(0, s, dp);
    }
};
