class Solution {
public:
    string check(int i, int j, string s){
        string ans;
        while(i >= 0 && j < s.size() && i <= j){
            if(s[i] != s[j]) break;
            i--;
            j++;
        }
        return s.substr(i+1, j-i-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();

        string ans = "";
        for(int i = 0; i < n; i++){
            string val1 = check(i, i, s);
            string val2 = "";
            if(i < n-1){
                val2 = check(i, i+1, s);
            }
            if(ans.size() < val1.size()){
                ans = val1;
            }
            if(ans.size() < val2.size()){
                ans = val2;
            }
        }
        return ans;
    }
};
