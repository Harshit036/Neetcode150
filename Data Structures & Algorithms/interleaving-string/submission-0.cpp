#include<bits/stdc++.h>
class Solution {
public:
    int dp[100][100][100];
    int func(int i, int j, int k, string s1, string s2, string s3){
        if(k == s3.size() && i == s1.size() && j == s2.size()) return true;
        if(k == s3.size()) return false;

        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(i != s1.size() && s1[i] == s3[k]){
            if(func(i+1, j, k+1, s1, s2, s3)) return dp[i][j][k] = true;   
        }
        if(j != s2.size() && s2[j] == s3[k]){
            if(func(i, j+1, k+1, s1, s2, s3)) return dp[i][j][k] = true;
        }
        return dp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof dp);
        int ans = func(0, 0, 0, s1, s2, s3);
        return ans;
    }
};
