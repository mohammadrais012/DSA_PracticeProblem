class Solution {
public:
    vector<string> result;
    void solve(string s, string digits,unordered_map<char,string>mp,int i){
        if(i>=digits.size()){
            result.push_back(s);
            return;
        }
        for(char ch : mp[digits[i]]){
            solve(s+ch,digits,mp,i+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;

        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        string s="";
        solve(s,digits,mp, 0);

        return result;
    }
};