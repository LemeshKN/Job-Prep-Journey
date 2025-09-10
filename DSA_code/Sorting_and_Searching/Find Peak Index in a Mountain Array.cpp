/*
------------------------------------------------------------------------------------
Problem Statement: Find Peak Index in a Mountain Array
------------------------------------------------------------------------------------

Link[https://leetcode.com/problems/peak-index-in-a-mountain-array/description/]

Description:
A mountain array has at least 3 elements and a single peak. The array strictly
increases before the peak and strictly decreases after it. Find the index of the peak.

Example:
Input: arr = [0, 2, 5, 3, 1]
Output: 2 (the index of the peak element 5)

------------------------------------------------------------------------------------
My Approach: Binary Search
Since the array has a distinct structure (increasing then decreasing), we can use
binary search to find the peak efficiently.

1.  Initialize `start` and `end` pointers at the beginning and end of the array.
2.  In each step, find the `mid` element and compare it with its right neighbor `mid+1`.
3.  If `arr[mid] < arr[mid+1]`, it means we are on the ascending slope of the mountain,
    so the peak must be to the right. We move our search space by setting `start = mid + 1`.
4.  If `arr[mid] > arr[mid+1]`, we are on the descending slope. The `mid` element could be
    the peak, so we shrink our search space from the right by setting `end = mid`.
5.  The loop continues until `start` and `end` meet, which will be at the peak index.

Time Complexity: O(log n).
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;
            // We are on the ascending part of the array
            if (arr[mid] < arr[mid + 1]) {
                s = mid + 1;
            } 
            // We are on the descending part, mid could be the peak
            else {
                e = mid;
            }
        }
        // When the loop ends, s and e will be pointing to the peak element
        return s;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This binary search implementation is the optimal solution for this problem. The logic
correctly narrows down the search space based on the slope of the mountain array,
guaranteeing an O(log n) time complexity. The use of the `s < e` condition is a
clean way to handle the convergence of the pointers.
------------------------------------------------------------------------------------
*/