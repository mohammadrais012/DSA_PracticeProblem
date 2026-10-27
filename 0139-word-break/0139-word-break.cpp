class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        int n = s.size();

        unordered_set<string> st(word.begin(),word.end());

        vector<int> dp(n+1);
        dp[0]=1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){

                if(dp[j] && st.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[n];
    }
};