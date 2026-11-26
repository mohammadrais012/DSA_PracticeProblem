class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10) return false;
        int i=0;
        int diff=10;
        while(true){
            if(n>=diff)
            n-=diff;
            else {
                break;
            }
            diff=diff-1;
            i++;
        }
        if(i%2!=0) return true;

        return false;
    }
};