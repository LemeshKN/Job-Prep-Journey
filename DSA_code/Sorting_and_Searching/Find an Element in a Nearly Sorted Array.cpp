/*
------------------------------------------------------------------------------------
Problem Statement:Find an Element in a Nearly Sorted Array
------------------------------------------------------------------------------------

Link: [https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1]

Description:
In a nearly sorted array, each element can be swapped with its adjacent elements.
An element that should be at index `i` can be at `i-1`, `i`, or `i+1`. Find the
index of a given `target` element.

Example:
Input: arr = [3, 5, 10, 9, 11], K = 10
Output: 2

------------------------------------------------------------------------------------
My Approach: Modified Binary Search
Since the array is "nearly" sorted, we can use a modified version of binary search.

1.  In each step of the binary search, calculate the `mid` index.
2.  Instead of just checking `arr[mid]`, we must also check its neighbors, `arr[mid-1]`
    and `arr[mid+1]`, as the target could be in one of these three positions.
3.  If the target is not found at `mid` or its neighbors, we can still shrink the
    search space.
4.  If `arr[mid] > target`, we know the target must be to the left, so we can safely
    move our `end` pointer to `mid - 2`.
5.  If `arr[mid] < target`, the target must be to the right, so we move our `start`
    pointer to `mid + 2`.

Time Complexity: O(log n).
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int findElementInNearlySortedArray(const std::vector<int>& arr, int K) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            // Case 1: Target is at mid
            if (arr[mid] == K) {
                return mid;
            }
            // Case 2: Target is at mid-1 (check bounds first)
            if (mid - 1 >= s && arr[mid - 1] == K) {
                return mid - 1;
            }
            // Case 3: Target is at mid+1 (check bounds first)
            if (mid + 1 <= e && arr[mid + 1] == K) {
                return mid + 1;
            }
            
            // If not found, shrink the search space
            if (arr[mid] > K) {
                // Target is in the left, we can skip mid and mid-1
                e = mid - 2;
            } else {
                // Target is in the right, we can skip mid and mid+1
                s = mid + 2;
            }
        }
        return -1;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is the correct and optimal way to solve this problem. Modifying the standard
binary search to check adjacent elements is the key insight. The logic to jump the
pointers by 2 (`mid-2`, `mid+2`) is also correct because you've already checked the
three positions around `mid`. This ensures the algorithm maintains its O(log n)
time complexity. I've added boundary checks for `mid-1` and `mid+1` to make the
code more robust against edge cases.
------------------------------------------------------------------------------------
*/