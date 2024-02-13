#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0;
        int c = matrix[0].size() - 1;
        while(r < matrix.size() && c >= 0){
            if(matrix[r][c] == target)
                return true;
            else if(target > matrix[r][c])
                r++;
            else
                c--;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    cout << "Target " << target << " is present in the matrix: " << (solution.searchMatrix(matrix, target) ? "true" : "false") << endl; // Output: true
    return 0;
}
