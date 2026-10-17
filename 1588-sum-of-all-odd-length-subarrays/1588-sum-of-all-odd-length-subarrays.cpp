class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();

        int result=0;
       

        for(int i =0; i<n; i++){
            int sum=0, len=0;
            for(int j=i; j<n; j++){
                sum+=arr[j];
                ++len;
                if((len)%2!=0) result+=sum;
              
            }
        }

        return result;
    }
};