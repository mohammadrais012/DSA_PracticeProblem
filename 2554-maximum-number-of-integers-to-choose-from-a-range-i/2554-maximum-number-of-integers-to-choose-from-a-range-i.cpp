class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s;

        for(int x: banned) s.insert(x);
        int sum=0, cnt=0;
        for(int i=1; i<=n; i++){
            if(s.find(i)==s.end() && sum+i<=maxSum){
                sum+=i;
                cnt++;
            }
        }

        return cnt;

    }
};