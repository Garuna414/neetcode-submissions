class Solution {
public:
    bool match (map<char, int>& mp1, map<char, int>& mp2) {
        for (auto p : mp1) {
            auto itr = mp2.find(p.first);
            if (p.second != itr->second) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp1, mp2;
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false;
        for (char c : s1) mp1[c]++;
        int k = 0, j = 0;
        while (j < len1) {
            mp2[s2[j++]]++;
        }
        if (match(mp1, mp2)) return true;
        j--;
        while (j < len2) {
            j++;
            mp2[s2[k]]--;
            k++;
            mp2[s2[j]]++;
            if (match(mp1, mp2)) return true;
        }
        return false;
    }
};
