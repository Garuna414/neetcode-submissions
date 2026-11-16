class Solution {
public:
    bool checkMp (map<char, int>& mp) {
        for (auto p : mp) {
            if (p.second > 1) return true;
        }
        return false;
    }
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int len = s.size(), i = 0, j = 1, maxLen = 1, currLen = 1;
        mp[s[i]]++;
        if (len <= 1) return len;
        while (j < len) {
            mp[s[j]]++;
            currLen++;
            if (mp[s[j]] > 1) {
                while (checkMp(mp)) {
                    mp[s[i]]--;
                    currLen--;
                    i++;
                }
            }
            maxLen = max(maxLen, currLen);
            j++;
        }
        return maxLen;
    }
};
