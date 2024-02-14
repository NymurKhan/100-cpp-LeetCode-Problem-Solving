#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int low = 0, high = nums.size() - 1;

        // search for the leftmost index
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                if (mid - 1 < 0 || nums[mid - 1] != target) {
                    ans.push_back(mid);
                    break;
                } else {
                    high = mid - 1;
                }
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans.empty()) ans.push_back(-1);

        low = 0, high = nums.size() - 1;
        // search for the rightmost index
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                if (mid + 1 > high || nums[mid + 1] != target) {
                    ans.push_back(mid);
                    break;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (ans.size() == 1) ans.push_back(-1);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10}; // Example input
    int target = 8; // Example target
    vector<int> result = sol.searchRange(nums, target);
    cout << "Indices of target in nums: " << result[0] << ", " << result[1] << endl;
    return 0;
}
