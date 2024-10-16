//water will be stored in a building if there is a larger building on left and right
//the ht of water stored over one building will be the min of maxht on left and maxht on right - ht of current tower
//sum up all heights and get the total trapped water
//run nested loop to find leftmax and right max
//TC : O(n^2) SC : O(1)

//we can store the leftmax and right max previously to access them in constant time 
//so we use prefix and suffix arr
//TC : O(3n) SC : O(2n)
//we can remove computing the prefix(left max)and calculate it using a varible while travering arr, this code i have written below
//TC : O(3n) SC : O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int right_max[n];
        right_max[n - 1] = height[n - 1];//right max of last element is the element itself
        for(int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        int left_max = height[0], total = 0;
        for(int i = 0; i < n; i++) {
            left_max = max(left_max,height[i]);
            // int water = min(left_max, right_max[i]) - height[i];
            // if(water > 0) total += water;
            if(left_max > height[i] && right_max[i] > height[i])
                total += min(left_max, right_max[i]) - height[i];
        }
        return total;
    }
};

//optimal approach using 2 ptr will be written later