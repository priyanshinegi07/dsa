//greedy : optimization problem(to find maximum or minimum) and sorted data
//this is an activity selection problem
//in order to get maximum activites done, we choose the activity that will be ending first and the we wil choose next activity which is non - overlapping
//we will sort the activities on the basis of end time, we can use a comparator(static inside class)
//tc : O(n)
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool compare_by_third_col(vector<int>&a, vector<int>&b) {
        return a[2] < b[2];
        
    }
    int maxMeetings(vector<int> start, vector<int> end) {
        // Your code here
        vector<vector<int>>meetings(start.size(), vector<int>(3));
        int n = start.size();
        for(int i = 0; i < n; i++) {
            meetings[i][0] = i;
            meetings[i][1] = start[i];
            meetings[i][2] = end[i];
            
        }
        // for(int i = 0; i < meetings.size(); i++) {
        //     cout<<meetings[i][0]<<meetings[i][1]<<meetings[i][2]<<endl;
        // }
        sort(meetings.begin(), meetings.end(), compare_by_third_col);
        int mx = 1;
        int last_choosen = 0;
        for(int i = 1; i < n; i++) {
            if(meetings[i][1] > meetings[last_choosen][2]) {
                mx++;
                last_choosen = i;
            }
        }
        return mx;
    }
};