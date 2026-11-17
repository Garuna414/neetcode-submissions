class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        int len = temp.size();
        vector<int> vec(len, 0);

        for (int i = len - 1; i >= 0; i--) {
            if (st.empty()) {
                vec[i] = 0;
                st.push(make_pair(temp[i],i));
            } else {
                if (temp[i] >= st.top().first) {
                    while (!st.empty() && temp[i] >= st.top().first) {
                        st.pop();
                    }
                    if (st.empty()) vec[i] = 0;
                    else vec[i] = st.top().second - i;
                    st.push(make_pair(temp[i], i));
                } else {
                    vec[i] = st.top().second - i;
                    st.push(make_pair(temp[i],i));
                }
            }
        }
        return vec;
    }
};
