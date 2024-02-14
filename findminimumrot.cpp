#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;

            if (nums[mid] < nums[next] && nums[mid] < nums[prev])
                return nums[mid];

            if (nums[mid] == nums[start] && nums[mid] == nums[end]) {
                start++;
                end--;
            } else if (nums[end] >= nums[mid]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return nums[start];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int minNum = sol.findMin(nums);
    cout << "Minimum element in the rotated sorted array: " << minNum << endl;
    return 0;
}
