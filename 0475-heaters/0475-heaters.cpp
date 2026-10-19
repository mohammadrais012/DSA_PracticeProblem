class Solution {
public:
    bool isValid(int mid , vector<int>& houses, vector<int>& heaters){
        int n = houses.size();
        int m = heaters.size();

        int i=0, j=0;

        while(i<n && j<m){
           long long left = (long long)heaters[j] - mid;
           long long right = (long long)heaters[j] + mid;

            if(left<= houses[i] && right>= houses[i]){
                i++;
            }
            else j++;
        }

        return i==n ;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        sort(begin(houses),end(houses));
        sort (begin(heaters),end(heaters));
        int lo = 0, first = *max_element(begin(houses),end(houses));
        int sec = *max_element(begin(heaters),end(heaters));

        int hi = max(first,sec);
        int ans=hi;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(isValid(mid, houses,heaters)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo= mid+1;
            }
        }

        return ans;
    }
};