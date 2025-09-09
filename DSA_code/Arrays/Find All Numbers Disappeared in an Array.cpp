/*
------------------------------------------------------------------------------------
Problem Statement: Find All Numbers Disappeared in an Array
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/]

Description:
Given an array `nums` of `n` integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in `nums`.

The algorithm must run in O(n) time and use O(1) extra space (the returned list 
does not count as extra space).

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Explanation: The numbers 5 and 6 are missing from the range [1, 8].

------------------------------------------------------------------------------------
My Approach: Cyclic Sort
This problem can be solved efficiently in-place using the Cyclic Sort pattern. The core
idea is that if the array contained all numbers from 1 to n perfectly, then the number
'x' would be at index 'x-1'.

1.  We iterate through the array. For each element `nums[i]`, we check if it is in its
    correct position (`nums[i] == i + 1`).
2.  If it's not, we swap it with the element at its correct index (`nums[nums[i]-1]`).
    We repeat this until the element at index `i` is correct, then we move to `i+1`.
3.  After this first pass, the array is almost sorted. A final pass through the array
    allows us to find the discrepancies. If `nums[i]` is not equal to `i+1`, then `i+1`
    is a missing number.

Time Complexity: O(n), as each number is placed in its correct position at most once.
Space Complexity: O(1), as the sorting is done in-place.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        // Phase 1: Cyclic Sort to place numbers in their correct indices
        while (i < n) {
            // The correct index for the number nums[i] should be nums[i] - 1.
            int correct_index = nums[i] - 1;
            
            // If the number is not at its correct index, swap it.
            if (nums[i] != nums[correct_index]) {
                std::swap(nums[i], nums[correct_index]);
            }
            // If the number is already at its correct index, move on.
            else {
                i++;
            }
        }
        
        std::vector<int> ans;
        
        // Phase 2: Find the missing numbers
        // If the number at an index is not the expected number, it's a missing one.
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & ALTERNATIVE SOLUTION ---
------------------------------------------------------------------------------------
The implemented Cyclic Sort pattern is a highly efficient and clever way to solve 
this problem, meeting both the O(n) time and O(1) space constraints.

Another powerful in-place method is the "Negative Marking" or "Visited" technique. 
This approach is also O(n) time and O(1) space and works as follows:

1.  Iterate through the array. For each number `nums[i]`, take its absolute value `x`.
2.  Use this value `x` as an index (`x-1`) and mark the number at that index as
    negative. This "marks" the number `x` as having been seen.
3.  After the first pass, iterate through the array again. If any number `nums[i]` is
    still positive, it means the number `i+1` was never seen in the original array,
    so it is one of the missing numbers.

Example implementation of the "Negative Marking" technique:
```cpp
/*
    vector<int> findDisappearedNumbers(vector<int>& nums){
        int n = nums.size();
        
        // Mark seen numbers by making the value at their corresponding index negative.
        for(int i=0; i<n; i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0){
                nums[index] = -nums[index];
            }
        }

        vector<int> ans;

        // Any index with a positive number means that index+1 was never seen.
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
*/