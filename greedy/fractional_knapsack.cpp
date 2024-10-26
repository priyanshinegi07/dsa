//we try to choose that item which has max val and min wt so that we can take max items that are favourable, we will be able to take max items and also maximize the value
class Solution {
  public:
    static bool compare_second_col(vector<double>&a, vector<double>&b) {
        return a[1] < b[1];
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
        // Your code here
        int n = values.size();
        vector<vector<double>>ratio(n, vector<double>(2, 0));
        for(int i = 0; i < n; i++) {
            ratio[i][0] = i;
            ratio[i][1] = values[i]/(double)weights[i];
        }
        sort(ratio.begin(), ratio.end(), compare_second_col);
    
    int capacity = w;
    double val = 0;
    for(int i = n - 1; i >= 0; i--) {
        int indx = (int)ratio[i][0];
        if(capacity >= weights[indx]) {
            capacity -= weights[indx];
            val += values[indx];
        }
        else {
            val += (ratio[i][1] * capacity);
            capacity = 0;
            break;
        }
    }
    return val;
}
};