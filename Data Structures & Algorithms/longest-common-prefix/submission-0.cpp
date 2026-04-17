class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool flag = true;
        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i];
            for(auto it : strs){
                if(i >= it.size() || it[i] != c){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            ans += c;
        }
        return ans;
    }
};