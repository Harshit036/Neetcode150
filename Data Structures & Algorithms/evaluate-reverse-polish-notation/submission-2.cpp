class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" && st.size() >= 2){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1+num2);
            } else if(tokens[i] == "-" && st.size() >= 2){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2-num1);
            } else if(tokens[i] == "*" && st.size() >= 2){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1*num2);
            } else if(tokens[i] == "/" && st.size() >= 2){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2/num1);
            } else {
                int num = stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};
