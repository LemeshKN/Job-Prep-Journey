/*
------------------------------------------------------------------------------------
Problem Statement: Print Extreme Elements Alternately
------------------------------------------------------------------------------------

Description:
Given an array of integers, your task is to output the elements in an alternating 
fashion, starting with the smallest, then the largest, followed by the next 
smallest, the next largest, and so on.

Example:
Input: [1, 3, 2, 4, 5]
Sorted: [1, 2, 3, 4, 5]
Output: [1, 5, 2, 4, 3]

------------------------------------------------------------------------------------
My Approach:
The most efficient way to solve this is a two-pointer approach after an initial sort.

1. First, sort the input array. This places the smallest elements at the beginning 
   and the largest elements at the end.
2. Initialize two pointers: `left` at the start of the array (index 0) and `right` 
   at the end of the array (index n-1).
3. Loop as long as `left` is less than or equal to `right`. In each iteration,
   add the element at the `left` pointer to our answer, then add the element at the 
   `right` pointer.
4. Move the pointers inward (`left++`, `right--`) and repeat until they cross. A special
   check handles arrays with an odd number of elements to avoid adding the middle 
   element twice.

Time Complexity: O(n log n), dominated by the sorting step.
Space Complexity: O(n), to store the resulting answer vector.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> printExtremeElementsAlternately(std::vector<int>& arr) {

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        std::vector<int> ans;
        int n = arr.size();
        
        // Step 2: Initialize two pointers
        int left = 0;
        int right = n - 1;
        
        // Step 3: Loop until the pointers meet or cross
        while (left <= right) {
            // Add the smallest available element
            ans.push_back(arr[left]);
            left++;
            
            // Add the largest available element, only if pointers haven't crossed
            if (left <= right) {
                ans.push_back(arr[right]);
                right--;
            }
        }
        return ans;
    }
};