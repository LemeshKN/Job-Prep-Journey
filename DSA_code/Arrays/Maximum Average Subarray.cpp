/*
------------------------------------------------------------------------------------
Problem Statement:Maximum Average Subarray
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/maximum-average-subarray-i/description/]

Description:
You are given an integer array `nums` and an integer `k`. You need to find the 
contiguous subarray of length `k` that has the maximum average and return its 
average value.

Example 1:
Input: nums=[1,12,-5,-6,50,3], k=4
Output: 12.75
Explanation: The subarray [12,-5,-6,50] has the maximum average 12.75.

------------------------------------------------------------------------------------
My Approach: Sliding Window
This problem is a classic case for the Sliding Window technique, which is highly
efficient for problems involving contiguous subarrays of a fixed size.

1.  First, calculate the sum of the initial window (the first `k` elements).
2.  Initialize `maxSum` with this initial sum.
3.  Then, iterate through the rest of the array, "sliding" the window one element
    at a time.
4.  In each step, update the window's sum by subtracting the element that is leaving
    the window and adding the element that is entering it.
5.  After each slide, compare the new sum with `maxSum` and update it if necessary.
6.  Finally, calculate the average by dividing the `maxSum` by `k`.

Time Complexity: O(n), as we only need to iterate through the array once.
Space Complexity: O(1), as we only use a few variables to store the sums.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        
        // Step 1: Calculate the sum of the first window of size k
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        double maxSum = sum;
        
        // Step 2: Slide the window from the k-th element to the end of the array
        for (int i = k; i < n; i++) {
            // Update the sum: add the new element, subtract the element that's leaving
            sum += nums[i] - nums[i - k];
            // Update the maximum sum found so far
            maxSum = std::max(maxSum, sum);
        }
        
        // Step 3: Calculate and return the maximum average
        return maxSum / k;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This solution using the Sliding Window technique is excellent. It is the most
optimal approach for this problem, achieving a linear time complexity of O(n) and
constant space complexity of O(1). The code is clean and directly implements the
algorithm. No further optimization is needed.
------------------------------------------------------------------------------------
*/