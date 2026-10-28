class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int n = nums.size();
       long long total_sum=0;
       for(int i=0; i<n; i++){
            total_sum+=nums[i];
       }

       long long target= total_sum%p;

       if(target==0) return 0;
        unordered_map<long long,long long> mp;
        mp[0]=-1;
        long long sum=0;
        int minLen=INT_MAX;
       for(int i=0; i<n; i++){
            sum+=nums[i];

            long long rem = sum%p;
             rem=(rem+p)%p;
            long long needed= (rem-target+p)%p;
           

            if(mp.find(needed)!=mp.end()){
                minLen=min(minLen,(int)(i-mp[needed]));
            }

           mp[rem]=i;
       }
   return (minLen == INT_MAX || minLen >= n) ? -1 : minLen;

    }
};