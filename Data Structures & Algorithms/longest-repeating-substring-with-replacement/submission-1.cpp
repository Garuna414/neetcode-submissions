class Solution {
public:
    bool chkmp (map<char,int>& mp, int k) {
        int maxc = 0, tot = 0;
        for (auto p : mp) {
            tot += p.second;
            maxc = max(maxc, p.second);
        }
        if (tot - maxc > k) return true;
        return false;
    }    
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int len = s.size(), i = 0, j = 0, res = j-i+1;
        // cout << "i: " << i << " j: " << j << " res: " << res << endl;
        while (j < len) {
            mp[s[j]]++;
            if (chkmp(mp, k)) {
                while (chkmp(mp,k)) {
                    mp[s[i]]--;
                    i++;
                }
            }
            res = max(res, j-i+1);
            j++;
            // cout << "i: " << i << " j: " << j << " res: " << res << endl;
        }
        return res;
    }
};
