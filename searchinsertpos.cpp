#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int idx = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] >= target) {
                idx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return idx;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6}; // Example input
    int target = 5; // Example target
    int result = sol.searchInsert(nums, target);
    cout << "Insert position of target: " << result << endl;
    return 0;
}
