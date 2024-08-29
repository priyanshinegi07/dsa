//brute. 
//first we sort so that close intervals which can be overlapped are together
//select one inteval go to every next interval. it is overlapping then expand the end of previous interval
//other check for second / next interval
//TC : O(nlogn +2n) SC : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();
        //take one interval
        for(int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            //skip the interval if it is already included
            if(!ans.empty() and ans.back()[1] >= end) {
                continue;
            }
            for(int j = i + 1; j < n; j++) {
                if(intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                }
                else {
                    break;
                }
            }
            ans.push_back({start, end});

        }
        return ans;
    }
};