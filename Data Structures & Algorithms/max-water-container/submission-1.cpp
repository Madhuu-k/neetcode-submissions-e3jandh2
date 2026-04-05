class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxVol = 0;
        while(left < right){
            int h = min(heights[left], heights[right]);
            int w = right - left;
            int vol = h * w;
            maxVol = max(maxVol, vol);

            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return maxVol;
    }
};
