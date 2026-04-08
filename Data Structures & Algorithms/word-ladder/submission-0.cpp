class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto it : wordList) st.insert(it);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            string word = v.first;
            int steps = v.second;
            if(word == endWord) return steps;
            for(int i = 0; i < word.size(); i++){
                string temp = word;
                for(char c = 'a'; c <= 'z'; c++){
                    temp[i] = c;
                    if(st.find(temp) != st.end()){
                        q.push({temp, steps+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
