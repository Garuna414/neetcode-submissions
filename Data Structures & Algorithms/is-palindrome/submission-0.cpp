class Solution {
public:
    bool isPalindrome(string s) {
        string clean_s = "";
        for (char c : s) {
            int asc = int(c);
            if ((asc>=97 && asc<=122) || (asc>=65 && asc<=90)) clean_s += tolower(c);
            else if (asc>=48 && asc<=57) clean_s += c;
        }
        string t = clean_s;
        reverse(t.begin(), t.end());
        cout << "t: " << t << "\nc: " << clean_s << endl;
        if (t == clean_s) return true;
        else return false;
    }
};
