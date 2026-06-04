class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int price : prices){
            minPrice = min(minPrice, price); // smallest value - to buy
            int profit = price - minPrice; // profit we make with current selling
            maxProfit = max(maxProfit, profit); // max profit
        }
        return maxProfit;
    }
};
