class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_set<int> st;
        long long sum = 0;
        long long ans = 0;

        int j = 0;

        for(int i = 0; i < nums.size(); i++) {

            while(st.count(nums[i])) {
                sum -= nums[j];
                st.erase(nums[j]);
                j++;
            }

            st.insert(nums[i]);
            sum += nums[i];

            while(i - j + 1 > k) {
                sum -= nums[j];
                st.erase(nums[j]);
                j++;
            }

            if(i - j + 1 == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};