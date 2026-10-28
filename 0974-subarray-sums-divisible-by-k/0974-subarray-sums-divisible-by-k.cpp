class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size();
        
        unordered_map<long long,long long> mp;
        mp[0]=1;
        
        long long currSum=0;
        long long count=0;
        
        for(int i=0; i<n; i++){
            currSum+=arr[i];
            
            long long rem = currSum%k;
            rem = rem<0 ? rem+k : rem;
            
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            
            mp[rem]++;
        }
        
        return count;
    }
};