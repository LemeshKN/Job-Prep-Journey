/*
------------------------------------------------------------------------------------
Problem Statement: 3Sum
------------------------------------------------------------------------------------

Link: [ https://leetcode.com/problems/3sum/]

Description:
Given an integer array nums, return all the unique triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 0, 1], [-1, -1, 2]]
Explanation: The triplets [-1, 0, 1] and [-1, -1, 2] are the valid unique 
combinations that produce a sum of zero.

------------------------------------------------------------------------------------
My Approach:
This solution first sorts the array to handle duplicates efficiently. It then uses a 
three-nested-loop approach to check every possible unique triplet. Inside the loops, 
it skips over any duplicate elements to ensure the final result contains only 
unique triplets.

Time Complexity: O(n^3), due to the three nested loops.
Space Complexity: O(1), not counting the space for the answer vector.
------------------------------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        // Sort the array to handle duplicates easily and to enable two-pointer approach later
        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        // Outer loop for the first element of the triplet
        for (int i = 0; i < n; i++) {
            // Skip duplicate elements for i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // Second loop for the second element
            for (int j = i + 1; j < n; j++) {
                // Skip duplicate elements for j
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                // Third loop for the third element
                for (int k = j + 1; k < n; k++) {
                    // This check for k is not strictly necessary in this O(n^3) version,
                    // but it's good practice for handling duplicates.
                    if (k > j + 1 && nums[k] == nums[k - 1]) {
                        continue;
                    }
                    
                    int first = nums[i];
                    int second = nums[j];
                    int third = nums[k];
                    
                    if (first + second + third == 0) {
                        vector<int> temp;
                        temp.push_back(first);
                        temp.push_back(second);
                        temp.push_back(third);
                        ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
The above O(n^3) solution is a good starting point (brute-force). A more optimal 
solution for this problem reduces the time complexity to O(n^2).

The Optimized 'Two-Pointer' Approach:
1. Sort the array.
2. Iterate through the array with the outer loop (for i).
3. For each element `nums[i]`, use two pointers, `left` (starts at `i+1`) and 
   `right` (starts at `n-1`).
4. Calculate the sum `nums[i] + nums[left] + nums[right]`.
   - If sum is 0, we found a triplet. Add it to the answer and move both pointers
     inward, skipping any duplicates.
   - If sum is less than 0, move the `left` pointer to the right to increase the sum.
   - If sum is greater than 0, move the `right` pointer to the left to decrease the sum.
5. This eliminates the third nested loop, making the solution much more efficient.
------------------------------------------------------------------------------------
*/