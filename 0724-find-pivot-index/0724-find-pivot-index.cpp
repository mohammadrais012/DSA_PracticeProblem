class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int totalSum=0;

        for(int x: nums) {
            totalSum+=x;
        }

        int curSum=0;

        for(int i=0; i<n; i++){
            if(i==0 && totalSum-nums[i]==0) return 0;
            if(i==n-1 && totalSum-nums[i]==0) return i;

            if(curSum==totalSum-curSum-nums[i]) return i;

            curSum+=nums[i];
        }

        return -1;
    }
};