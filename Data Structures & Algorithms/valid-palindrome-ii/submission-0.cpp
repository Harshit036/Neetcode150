class Solution {
public:
    bool check(int i, int j, string s, bool flag){
        while(i < j){
            if(s[i] != s[j]){
                if(flag){
                    return check(i+1, j, s, false) || check(i, j-1, s, false);
                } else {
                    return false;
                }
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        return check(0, n-1, s, true);
    }
};