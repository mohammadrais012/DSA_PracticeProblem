class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s;

        for(int x: nums) {
            s.insert(x);
        }
        int i=1;
        while(true){
            if(s.find(i)==s.end()) return i;
            i++;
        }

        return -1;
    }
};