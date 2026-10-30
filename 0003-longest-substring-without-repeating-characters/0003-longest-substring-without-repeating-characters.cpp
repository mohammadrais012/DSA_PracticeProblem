class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> st;

        int maxlen =0, j=0;
        for(int i=0; i<n; i++){

            while(st.find(s[i])!=st.end()){
                st.erase(s[j]);
                j++;
            }

            st.insert(s[i]);
            maxlen = max(maxlen , i-j+1);
        }

        return maxlen;
    }
};