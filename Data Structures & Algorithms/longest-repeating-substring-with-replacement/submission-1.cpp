class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> st;
        for(auto it : s) st.insert(it);
        int i = 0, j = 0;
        int maxi = 0;
        for(auto it : st){
            int ans = 0;
            int temp = k;
            j = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != it) temp--;
                while(temp < 0){
                    if(s[j] != it){
                        temp++;
                    }
                    j++;
                }
                ans = max(ans, i-j+1);
            }
            maxi = max(maxi, ans);
        }
        return maxi;
    }
};
