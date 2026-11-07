class Solution {
public:
    int getNumber(int n){
        int ans = 0;
        while(n > 0){
            int d = n % 10;
            ans += (d * d);
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_map<int,int> mp;

        while(n != 1){
            n = getNumber(n);

            if(mp.find(n) != mp.end()){ 
                return false; 
            }
            mp[n] = 1;
        }
        return true;
    }
};