class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int x: nums){
            mp[x]++;
        }
        int sum=0;
        for(auto it: mp){
            if(it.second%k==0){
                sum+= (it.first*it.second);
            }
        }

        return sum;
    }
};