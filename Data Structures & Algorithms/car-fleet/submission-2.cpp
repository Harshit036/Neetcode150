class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> v;
        stack<double> st;
        for(int i = 0; i < n; i++) v.push_back({position[i], speed[i]});

        sort(v.begin(), v.end());
        int count = 0;
        for(int i = n-1; i >= 0; i--){
            double time = (target - v[i].first) / (v[i].second * 1.0);
            // cout << v[i].first << " " << v[i].second << " " << time << "\n";
            if(st.empty() || st.top() < time){
                while(!st.empty() && st.top() < time){ 
                    st.pop(); 
                }
                count++;
                st.push(time);
            } 
        }
        return count;
    }
};
