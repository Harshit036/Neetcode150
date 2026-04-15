class Solution {
public:
    bool check(map<char, int> &mp){
        for(auto it : mp){
            if(it.second > 0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char, int> mp;
        for(int i = 0; i < t.size(); i++) 
            mp[t[i]]++;

        int j = 0, mini = 1e9;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]--;

                while(check(mp)){ 
                    if(mini > i-j+1){
                        mini = i-j+1;
                        ans = s.substr(j, i-j+1);
                    }
                    if(mp.find(s[j]) != mp.end()){
                        mp[s[j]]++;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
