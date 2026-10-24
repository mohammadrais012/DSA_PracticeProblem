class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int x: nums) st.insert(x);

        int dis = st.size();

        unordered_map<int,int> mp;
        int j=0, ans=0;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;

            while(mp.size()==dis){
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);

                ans+=n-i;
                j++;
            }
        }

        return ans;
    }
};