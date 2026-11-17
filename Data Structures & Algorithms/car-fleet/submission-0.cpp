class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& spd) {
        int len = pos.size();
        vector<float> time(len);
        vector<pair<int, int>> ds(len);
        for (int i = 0; i < len; i++) {
            ds[i] = make_pair(pos[i], spd[i]);
        }
        sort(ds.begin(), ds.end(), [](pair<int,int>&a, pair<int,int>&b){
            return a.first < b.first;
        });
        for (int i = 0; i < len; i++) {
            float t = (target - ds[i].first) / (ds[i].second * 1.0);
            time[i] = t;
            cout << time[i] << endl;
        }
        set<float> st;
        st.insert(time[len-1]);
        for (int i = len-2; i >= 0; i--) {
            // cout << time[i] << " " << time[i+1] << endl;
            if (time[i] < time[i+1]) time[i] = time[i+1];
            else if (time[i] > time[i+1]) st.insert(time[i]);
        }
        return st.size();
    }
};
