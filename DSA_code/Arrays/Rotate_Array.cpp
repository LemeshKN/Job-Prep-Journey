/*
------------------------------------------------------------------------------------
Problem Statement: Rotate an Array
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/rotate-array/description/]

Description:
Given an array of integers `nums` and a non-negative integer `k`, your task is to 
rotate the array to the right by `k` steps.

You must do this in-place with a space complexity of O(1).

Example 1:
Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
Output: [5, 6, 7, 1, 2, 3, 4]
Explanation:
rotate 1 step: [7, 1, 2, 3, 4, 5, 6]
rotate 2 steps: [6, 7, 1, 2, 3, 4, 5]
rotate 3 steps: [5, 6, 7, 1, 2, 3, 4]

------------------------------------------------------------------------------------
My Approach:
This solution uses an auxiliary array (`temp`) to solve the problem. 
1. First, it handles cases where k is larger than the array size by using the modulo operator.
2. It stores the last `k` elements, which will become the new start of the array, into the `temp` vector.
3. It then shifts the first `n-k` elements to the right by `k` positions.
4. Finally, it copies the elements from the `temp` vector back into the first `k` positions of the original array.

Time Complexity: O(n), as we iterate through the array elements a constant number of times.
Space Complexity: O(k), as we use an auxiliary array of size k to store elements.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        // Handle cases where k >= n
        k = k % n;
        if (k == 0) return;
        
        // Create a temporary vector to store the last k elements
        std::vector<int> temp;
        for (int i = n - k; i < n; i++) {
            temp.push_back(nums[i]);
        }
        
        // Shift the first n-k elements to the right
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        
        // Copy the stored elements to the front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
The provided solution correctly rotates the array. It's a clear and logical approach.

However, the problem statement includes a critical constraint: solve it with 
**O(1) space complexity** (meaning, without using significant extra memory). 
Because this solution uses a temporary vector of size `k`, its space complexity is O(k), 
which does not meet this requirement.

The most common and efficient O(1) space solution uses a three-step reversal algorithm:

Let's use the example: nums = [1, 2, 3, 4, 5, 6, 7], k = 3

1.  **Reverse the entire array:**
    [7, 6, 5, 4, 3, 2, 1]

2.  **Reverse the first k elements (from index 0 to k-1):**
    [5, 6, 7, 4, 3, 2, 1]

3.  **Reverse the remaining n-k elements (from index k to n-1):**
    [5, 6, 7, 1, 2, 3, 4]  <-- This is the correct answer!

This reversal technique is a very powerful pattern for array manipulation problems 
and a great one to remember for interviews as it perfectly meets the O(1) space constraint.
------------------------------------------------------------------------------------
*/