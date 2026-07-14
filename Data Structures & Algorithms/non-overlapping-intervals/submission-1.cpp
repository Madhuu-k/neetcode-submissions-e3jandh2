class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort The Intervals First
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });

        int n = intervals.size();
        int count = 0;

        // Since We Sorted Them The Order Should be Growing
        // To Identify Overlapping Intervals Check For - 
        // If End Time of an Interval is Greater Than Start Time of Other Interval

        // BF - interval[i][1] > interval[i + 1][0] - Can go out of bounds
        
        int lastEnd = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(lastEnd > intervals[i][0]) count++;
            else lastEnd = intervals[i][1];
        }

        return count;
    }
};
