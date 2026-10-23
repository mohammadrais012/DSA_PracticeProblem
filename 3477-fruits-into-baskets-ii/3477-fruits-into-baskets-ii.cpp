class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int n = fruits.size();
        int i=0, j=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(fruits[i]<=baskets[j]){
                    cnt++;
                    baskets[j]=0;
                    break;
                } 
            }
        }

        return n-cnt;
    }
};