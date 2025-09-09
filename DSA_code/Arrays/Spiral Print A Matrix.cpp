/*
------------------------------------------------------------------------------------
Problem Statement:Spiral Print A Matrix
------------------------------------------------------------------------------------

Link: [https://leetcode.com/problems/spiral-matrix/description/]

Description:
Given a 2D matrix of size m x n, traverse the matrix in a spiral order and return 
the elements in a single list. The spiral order starts from the top-left corner 
going right, then down, then left, and finally up, continuing spirally until all 
elements are traversed.

Example:
Input: matrix = [ [1, 2, 3], [4, 5, 6], [7, 8, 9] ]
Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]

------------------------------------------------------------------------------------
My Approach: Four-Pointer Boundary Traversal
This is the classic and most efficient approach for spiral traversal problems. It
uses four pointers to keep track of the boundaries of the current layer of the spiral.

1.  Initialize four pointers: `top`, `bottom`, `left`, and `right` to define the
    outermost boundaries of the matrix.
2.  Use a `while` loop that continues as long as the boundaries have not crossed
    (i.e., `top <= bottom` and `left <= right`).
3.  Inside the loop, traverse the four sides of the current layer in order:
    a. Print the `top` row from `left` to `right`, then move the `top` boundary down.
    b. Print the `right` column from `top` to `bottom`, then move the `right` boundary left.
    c. Print the `bottom` row from `right` to `left`, then move the `bottom` boundary up.
    d. Print the `left` column from `bottom` to `top`, then move the `left` boundary right.
4.  The loop continues, shrinking the boundaries inward, until all elements are traversed.

Time Complexity: O(m * n), as we visit every element exactly once.
Space Complexity: O(m * n), to store the resulting answer vector.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        // Initialize boundary pointers
        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        // Loop until the boundaries cross
        while (top <= bottom && left <= right) {
            // 1. Traverse the top row from left to right
            for (int col = left; col <= right; col++) {
                ans.push_back(matrix[top][col]);
            }
            top++; // Move the top boundary down

            // 2. Traverse the right column from top to bottom
            for (int row = top; row <= bottom; row++) {
                ans.push_back(matrix[row][right]);
            }
            right--; // Move the right boundary left

            // 3. Traverse the bottom row from right to left (check if boundary is still valid)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    ans.push_back(matrix[bottom][col]);
                }
                bottom--; // Move the bottom boundary up
            }

            // 4. Traverse the left column from bottom to top (check if boundary is still valid)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    ans.push_back(matrix[row][left]);
                }
                left++; // Move the left boundary right
            }
        }
        return ans;
    }
};

/*
------------------------------------------------------------------------------------
--- REVIEW & OPTIMIZATION ---
------------------------------------------------------------------------------------
This four-pointer boundary traversal is the standard, optimal algorithm for solving
the spiral matrix problem. The logic is sound and correctly handles both square and
rectangular matrices by including boundary checks (`if (top <= bottom)`) before
traversing the bottom and left sides. This prevents double-counting elements in
matrices with a single row or column. The solution is efficient and well-implemented.
------------------------------------------------------------------------------------
*/