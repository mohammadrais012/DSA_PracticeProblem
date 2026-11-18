class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> freq(1001,0);

        for(auto it : trips){
            freq[it[1]]+=it[0];
            freq[it[2]]-=it[0];

        }
        int sum=capacity;
        for(auto it: freq){
            sum-=it;

            if(sum<0) return false;
        }

        return true;
    }
};