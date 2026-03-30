class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto it : strs){
            string temp = it;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(it);
        }
        vector<vector<string>> ans;
        for(auto it : mp){
            vector<string> temp;
            for(auto p : mp[it.first]) temp.push_back(p);
            ans.push_back(temp);
        }
        return ans;
    }
};
