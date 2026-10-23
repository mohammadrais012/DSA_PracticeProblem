class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> st;
        int j=0;

        long long sum=0, maxSum=0;
        for(int i=0; i<n; i++){
           while(st.find(nums[i])!=st.end() || i-j+1>k){
                st.erase(nums[j]);
                sum-=nums[j];
                j++;
            }
            sum+=nums[i];
            st.insert(nums[i]);
            int currLen=i-j+1;
            if( currLen==k){
                maxSum=max(maxSum,sum);
            }

        }
        return maxSum;
    }
};