class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int sum=0, minLen = INT_MAX;
        int j=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];

            while(sum>= target){
                sum-=nums[j];
                minLen=min(minLen, i-j+1);
                j++;
            }
        }

        if(minLen == INT_MAX) return 0;

        return minLen;
    }
};