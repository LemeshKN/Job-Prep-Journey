/*
------------------------------------------------------------------------------------
Problem Statement:Find the Mode of the Array
------------------------------------------------------------------------------------

Description:
Given an array of integers, determine the mode of the array. The mode is the element 
that appears most frequently. If there is more than one element with the highest 
frequency, return the smallest of these elements.

Example 1:
Input: [3, 3, 2, 1, 5, 1]
Output: 1
Explanation: The numbers 3 and 1 both appear twice, but 1 is smaller than 3, so 1 
is the mode.

------------------------------------------------------------------------------------
My Approach: Sort and Iterate
This approach first sorts the array. Sorting groups identical elements together,
making it easy to count their frequencies in a single pass.

1.  Create a copy of the input array to avoid modifying the original.
2.  Sort the copied array. This ensures that if there's a tie in frequency, the 
    smaller number will be considered the mode naturally due to the iteration order.
3.  Iterate through the sorted array, keeping track of the current element's frequency.
4.  If a new highest frequency is found, update the maximum frequency and the mode.

Time Complexity: O(n log n), dominated by the sorting step.
Space Complexity: O(n), because we create a copy of the input array.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMode(const std::vector<int>& nums) {
        // Handle empty or single-element arrays
        if (nums.empty()) return 0; // Or handle as an error
        if (nums.size() == 1) return nums[0];
        
        // Create a mutable copy to sort
        std::vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int maxFreq = 0;   // Stores the highest frequency found so far
        int mode = arr[0]; // Stores the mode, initialized to the first element
        int currentFreq = 1; // Stores the frequency of the current element being checked

        // Iterate from the second element to compare with the previous one
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                // If the current element is the same as the previous, increment its frequency
                currentFreq++;
            } else {
                // If we encounter a new number, reset the frequency counter
                currentFreq = 1;
            }
            
            // If the current element's frequency is greater than the max frequency found so far...
            if (currentFreq > maxFreq) {
                // ...update the max frequency and set the current element as the new mode.
                maxFreq = currentFreq;
                mode = arr[i];
            }
        }
        return mode;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
The Sort and Iterate approach is a solid and easy-to-understand solution. Its main
drawback is the O(n log n) time complexity from the sort.

A more time-efficient alternative is to use a Hash Map (or `std::unordered_map` in C++).

The Hash Map Approach:
1.  Iterate through the array once and store the frequency of each number in the map. (Time: O(n))
2.  Iterate through the map to find the number with the highest frequency, handling the
    tie-breaking rule (smallest number wins). (Time: O(n), as map size <= n)

This approach has a time complexity of O(n) and a space complexity of O(n), making
it faster for large, unsorted arrays.
------------------------------------------------------------------------------------
*/