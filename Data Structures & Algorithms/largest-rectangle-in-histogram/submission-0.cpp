class Solution {
public:
    void left(vector<int> &arr, vector<int>& nextleft){
        stack<pair<int, int>> st;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(!st.empty() && arr[i] <= st.top().first){
                while(!st.empty() && arr[i] <= st.top().first)
                    st.pop();
            }
            if(st.empty()) nextleft[i] = -1;
            else nextleft[i] = st.top().second;
            st.push({arr[i], i});
        }

    }
    void right(vector<int> &arr, vector<int>& nextright){
        stack<pair<int, int>> st;
        int n = arr.size();
        for(int i = n-1; i >=0; i--){
            if(!st.empty() && arr[i] <= st.top().first){
                while(!st.empty() && arr[i] <= st.top().first)
                    st.pop();
            }
            if(st.empty()) nextright[i] = arr.size();
            else nextright[i] = st.top().second;
            st.push({arr[i], i});
        }

    }
    int largestRectangleArea(vector<int>& heights) {
        // ye hoga bc next smaller to left and right se
        int n= heights.size();
        vector<int> nextleft(n);
        vector<int> nextright(n);
        left(heights, nextleft);
        right(heights, nextright);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, (nextright[i]-nextleft[i]-1)*heights[i]);
        }
        return maxi;
    }
};
