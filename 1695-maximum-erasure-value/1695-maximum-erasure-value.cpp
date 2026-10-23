class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n =nums.size();
        int sum=0, maxSum=0;
        unordered_set<int> st;
        int j=0;
        for(int i=0; i<n; i++){
            while(st.find(nums[i])!=st.end()){
                st.erase(nums[j]);
                sum-=nums[j];
                j++;
            }
            sum+=nums[i];

            maxSum=max(maxSum,sum);

            st.insert(nums[i]);

        }

        return maxSum;
    }
};