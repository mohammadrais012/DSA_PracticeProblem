class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word) {
            words.push_back(word);
        }

        if(words.size() != pattern.size()) return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;

        for(int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if(mp.find(c) != mp.end()) {
                if(mp[c] != w) return false;
            }
            mp[c] = w;

            if(mp2.find(w) != mp2.end()) {
                if(mp2[w] != c) return false;
            }
            mp2[w] = c;
        }

        return true;
    }
};
