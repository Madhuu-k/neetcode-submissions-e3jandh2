class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0, capacity = 0, start = 0;
        for(int i = 0; i < gas.size(); i++){
            int gain = gas[i] - cost[i];
            tank += gain;
            capacity += gain;
            if(capacity < 0){
                capacity = 0;
                start = i + 1;
            }
        }
        return tank >= 0 ? start : -1;
    }
};
