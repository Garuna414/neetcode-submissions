class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string s : tokens) {
            if (s != "+" && s != "-" && s != "*" && s != "/") {
                int i = stoi(s);
                st.push(i);
            } else {
                int o2 = st.top();
                st.pop();
                int o1 = st.top();
                st.pop();
                if (s == "+") st.push(o1 + o2);
                else if (s == "-") st.push(o1 - o2);
                else if (s == "*") st.push(o1 * o2);
                else if (s == "/") st.push(o1 / o2);
            }
        }
        return st.top();
    }
};
