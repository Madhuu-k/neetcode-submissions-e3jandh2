class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, startPos = 0, curr = 0;
        for(int i = 0; i < gas.size(); i++){
            int gain = gas[i] - cost[i];
            tank += gain;
            curr += gain;

            if(curr < 0){
                curr = 0;
                startPos = i + 1;
            }
        }
        return tank >= 0 ? startPos : -1;
    }
};
