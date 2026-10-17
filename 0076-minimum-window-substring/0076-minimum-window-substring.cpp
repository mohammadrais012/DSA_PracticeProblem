class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        if (t.size() > s.size()) return ans;

        unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        int minlen = INT_MAX, j = 0;
        int st = -1;
        int required = mp.size(); // Number of unique characters needed
        int match = 0;

        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) match++;
            }

            while (match == required) {
                if (minlen > i - j + 1) {
                    minlen = i - j + 1;
                    st = j;
                }
                if (mp.find(s[j]) != mp.end()) {
                    if (mp[s[j]] == 0) match--; // Decrement match before increasing frequency
                    mp[s[j]]++;
                }
                j++;
            }
        }

        if (st == -1) return ans;
        return s.substr(st, minlen);
    }
};