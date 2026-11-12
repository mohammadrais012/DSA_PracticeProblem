class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int>mp;

        for (char ch :magazine ){
            if(mp.find(ch)!=mp.end()){
                mp[ch]++;
            }
            else{
                mp[ch]=1;
            }
        }

        for(char ch :ransomNote ){
            if(mp.find(ch)==mp.end()){
                return false;
            }
           mp[ch]--;
           if (mp[ch] == 0) {
             mp.erase(ch);
        }
            
           
        } 

        return true;
        
    }
};