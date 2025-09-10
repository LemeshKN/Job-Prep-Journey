/*
------------------------------------------------------------------------------------
Problem Statement: Find First and Last Occurrence of an Element in a Sorted Array
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/]

Description:
Given a sorted array of integers `nums` and an integer `target`, your task is to 
identify the starting and ending positions of `target`. If `target` does not exist,
return [-1, -1]. The algorithm should have a time complexity of O(log N).

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3, 4]

------------------------------------------------------------------------------------
My Approach: Two Modified Binary Searches
This problem can be solved efficiently by using binary search twice.

1.  **First Occurrence:** A modified binary search is used to find the leftmost 
    (first) occurrence of the target. When an instance of the target is found at `mid`,
    we store it as a potential answer and then try to find an earlier occurrence by
    shrinking the search space to the left (`e = mid - 1`).
2.  **Last Occurrence:** A second modified binary search is used to find the rightmost
    (last) occurrence. When an instance is found at `mid`, we store it and shrink
    the search space to the right (`s = mid + 1`) to find a later occurrence.

Time Complexity: O(log n), because we perform two separate binary searches.
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int FirstOccurr(std::vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                // Potential answer found, try to find an even earlier one on the left
                ans = mid;
                e = mid - 1;
            } else if (nums[mid] < target) {
                // Target is in the right half
                s = mid + 1;
            } else {
                // Target is in the left half
                e = mid - 1;
            }
        }
        return ans;
    }

    int LastOccurr(std::vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                // Potential answer found, try to find an even later one on the right
                ans = mid;
                s = mid + 1;
            } else if (nums[mid] < target) {
                // Target is in the right half
                s = mid + 1;
            } else {
                // Target is in the left half
                e = mid - 1;
            }
        }
        return ans;
    }
    
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first = FirstOccurr(nums, target);
        int last = LastOccurr(nums, target);
        return {first, last};
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is the standard and optimal approach for this problem. Using two modified
binary searches correctly finds both occurrences in O(log n) time. The logic is
sound and well-implemented.
------------------------------------------------------------------------------------
*/