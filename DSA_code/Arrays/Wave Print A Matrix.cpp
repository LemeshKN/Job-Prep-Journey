/*
------------------------------------------------------------------------------------
Problem Statement: Wave Print A Matrix
------------------------------------------------------------------------------------

Description:
Given a 2D matrix of size m x n, your task is to return its elements arranged in a 
'wave' order. This means starting from the top-most row and printing elements down 
in one column, then moving to the next column and printing them up, and continuing 
this zig-zag pattern.

Example 1:
Input: m=3, n=3, matrix=[[1,2,3],[4,5,6],[7,8,9]]
Output: 1 4 7 8 5 2 3 6 9
Explanation: Wave order (col-wise): 1 4 7 (down), then 8 5 2 (up), then 3 6 9 (down).

------------------------------------------------------------------------------------
My Approach: Column-wise Traversal with Alternating Direction
This solution directly implements the logic described in the problem.

1.  Iterate through the matrix column by column (from column 0 to n-1).
2.  For each column, check if its index is even or odd.
3.  If the column index is even, traverse that column downwards (from row 0 to m-1)
    and add the elements to the answer.
4.  If the column index is odd, traverse that column upwards (from row m-1 to 0)
    and add the elements to the answer.

Time Complexity: O(m * n), as we visit every element in the matrix exactly once.
Space Complexity: O(m * n), to store the resulting answer vector.
------------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> wavePrintMatrix(std::vector<std::vector<int>>& matrix, int m, int n) {
        std::vector<int> ans;
        
        // Iterate through each column
        for (int col = 0; col < n; col++) {
            // Check if the column index is even
            if (col % 2 == 0) {
                // For even columns, traverse downwards
                for (int row = 0; row < m; row++) {
                    ans.push_back(matrix[row][col]);
                }
            } else {
                // For odd columns, traverse upwards
                for (int row = m - 1; row >= 0; row--) {
                    ans.push_back(matrix[row][col]);
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
This is a perfect and direct solution to the problem. The logic is clean, easy to 
follow, and correctly implements the wave traversal. It visits each element exactly 
once, making it optimally efficient with a time complexity of O(m * n). No further
optimizations are necessary.
------------------------------------------------------------------------------------
*/