class Solution {
public:
    int wateringPlants(vector<int>& plants, int cap) {
        int n = plants.size();

        int steps =0;
        int remWater=cap;
        for(int i=0; i<n; i++){
            if(remWater>=plants[i]){
                steps++;
                remWater-=plants[i];
            }
            else{
                steps+= 2*i+1;
                remWater=cap-plants[i];
            }
        }
        return steps;
    }
};