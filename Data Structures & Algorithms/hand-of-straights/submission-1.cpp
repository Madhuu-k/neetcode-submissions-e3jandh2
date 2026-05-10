class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
       
        sort(hand.begin(), hand.end());

        unordered_map<int, int> freq;;
        for(int x : hand) freq[x]++;

        for(int x : hand){
            if(freq[x] == 0) continue;

            for(int i = 0; i < groupSize; i++){
                int curr = x + i;
                if(freq[curr] == 0) return false;
                freq[curr]--;
            }
        }

        return true;
    }
};
