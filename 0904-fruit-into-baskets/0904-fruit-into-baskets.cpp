class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int j=0, maxLen=0;

        for(int i=0; i<n; i++){
            mp[fruits[i]]++;

            while(mp.size()>2){
                mp[fruits[j]]--;
                if(mp[fruits[j]]==0){
                    mp.erase(fruits[j]);
                }
                j++;
            }

            maxLen = max(maxLen, i-j+1);
        }

        return maxLen;
    }
};