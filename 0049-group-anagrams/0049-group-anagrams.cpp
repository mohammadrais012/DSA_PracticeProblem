class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        vector<vector<string>> result;

        unordered_map<string, vector<string>> mp;
        for(string word : s){
            vector<int> freq(26,0);

            for(char ch : word){
                freq[ch-'a']++;
            }
            string key="";

            for(int i=0; i<26;i++){
                key+=to_string(freq[i])+"$";
            }

            mp[key].push_back(word);
        }

        for(auto it : mp){
            result.push_back(it.second);
        }

        return result;
    }
};