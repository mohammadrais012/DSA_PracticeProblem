class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]=i;
        }

        for(auto it: operations){
            int idx= mp[it[0]];
            nums[mp[it[0]]]=it[1];
            mp.erase(it[0]);
            mp[it[1]]=idx;
        }

        return nums;
    }
};