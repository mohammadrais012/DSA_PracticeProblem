class Solution {
public:
    bool checkString(string s) {
        int n = s.size();

        int count=1;

        int i=0;

        while(i<n){
            if(s[i]=='b') break;
            i++;
        }

        while(i<n){
            if(s[i]=='a') return false;
            i++;
        }

        return true;
    }
};