class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros=0, maxlen=0;
        int j=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) zeros++;

            while(zeros>k){
                if(nums[j]==0) zeros--;
                j++;
            }
            maxlen=max(maxlen, i-j+1);
        }
        return maxlen;
    }
};