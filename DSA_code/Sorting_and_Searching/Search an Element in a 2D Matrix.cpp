/*
------------------------------------------------------------------------------------
Problem Statement: Search an Element in a 2D Matrix
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/search-a-2d-matrix/description/]

Description:
You are provided with an m x n matrix where each row is sorted, and the first
integer of each row is greater than the last integer of the previous row. 
Your task is to find out whether a given `target` number exists in this matrix.

Example:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

------------------------------------------------------------------------------------
My Approach: Binary Search on a Flattened 2D Array
This solution treats the `m x n` matrix as a flattened, sorted 1D array of size
`m * n`. This allows us to apply binary search directly.

1.  Initialize `start = 0` and `end = (m*n) - 1`.
2.  In each step, calculate the `mid` index for the conceptual 1D array.
3.  Convert this 1D `mid` index back to 2D coordinates:
    - `rowIndex = mid / numberOfColumns`
    - `colIndex = mid % numberOfColumns`
4.  Compare the element at `matrix[rowIndex][colIndex]` with the target and adjust
    the `start` and `end` pointers just like a standard binary search.

Time Complexity: O(log(m*n)).
Space Complexity: O(1).
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col;
        int s = 0;
        int e = total - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int rowIndex = mid / col;
            int colIndex = mid % col;
            
            int element = matrix[rowIndex][colIndex];
            
            if (element == target) {
                return true;
            }
            if (element > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return false;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This is a very clever and optimal solution for this specific type of matrix, where
the rows are sorted and sequentially ordered. Treating the 2D matrix as a virtual
1D array is the most efficient approach, yielding an O(log(m*n)) time complexity.

It's important to note that for a different version of this problem where only the
rows and columns are sorted independently (but not necessarily sequentially), a
different "staircase search" algorithm with O(m+n) complexity would be used.
Recognizing which problem you're solving is key, and you've chosen the perfect
algorithm for this version.
------------------------------------------------------------------------------------
*/