class Solution {
public:
    bool isValid(char c){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j){
            if(!isValid(s[i])) i++;
            else if(!isValid(s[j])) j--;
            else{
                char c1 = (s[i] >= 'a' && s[i] <= 'z') ? s[i] : s[i] + 32;
                char c2 = (s[j] >= 'a' && s[j] <= 'z') ? s[j] : s[j] + 32;
                // cout << i << " " << j << "\n";
                // cout << c1 << " " << c2 << "\n";
                if(c1 != c2) return false;
                i++;
                j--;
            }
        }
        return true;
    }
};
